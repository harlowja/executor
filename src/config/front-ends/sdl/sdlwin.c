/* Copyright 1994 - 1999 by Abacus Research and
 * Development, Inc.  All rights reserved.
 */

#if !defined (OMIT_RCSID_STRINGS)
char ROMlib_rcsid_sdlwin[] = "$Id: sdlwin.c 63 2004-12-24 18:19:43Z ctm $";
#endif

#include "rsys/common.h"
#include "rsys/srcblt.h"
#include "rsys/refresh.h"

#if defined (CYGWIN32)
#include "win_screen.h"
#endif

#include "SDL/SDL.h"

#include "sdlevents.h"
#include "syswm_map.h"

#if defined (linux) && !defined (powerpc) && !defined (__ppc__)
#define USE_SDL_EVENT_THREAD
#include "sdlX.h"
#endif

/* This is our video display */
static SDL_Surface *screen;

/* These variables are required by the vdriver interface. */
uint8 *vdriver_fbuf;
int vdriver_row_bytes;
int vdriver_width = 0;
int vdriver_height = 0;
int vdriver_bpp = 8, vdriver_log2_bpp;
int vdriver_max_bpp, vdriver_log2_max_bpp;
vdriver_modes_t *vdriver_mode_list;

/* Currently a private colormap is the default */
static int video_flags = (SDL_SWSURFACE|SDL_HWPALETTE);

/* The modes structure is just checked for error messages, fake it here */
static vdriver_modes_t sdl_impotent_modes = { 0, 0 };


/* SDL vdriver implementation */

void
vdriver_opt_register (void)
{
}

PUBLIC boolean_t ROMlib_fullscreen_p = FALSE;
PUBLIC boolean_t ROMlib_hwsurface_p = FALSE;

boolean_t
vdriver_init (int _max_width, int _max_height, int _max_bpp,
	      boolean_t fixed_p, int *argc, char *argv[])
{
  int flags;

  flags = SDL_INIT_VIDEO;
#if defined (USE_SDL_EVENT_THREAD)
  ROMlib_XInitThreads ();
  flags |= SDL_INIT_EVENTTHREAD;
#endif

  if ( SDL_Init(flags) < 0 )
    return(FALSE);
  sdl_events_init();

#if 0
  {
    SDL_PixelFormat format;

    /* Find out our "best" pixel depth */
    SDL_GetDisplayFormat(&format);
    vdriver_max_bpp = format.BitsPerPixel;
  }
#else
  vdriver_max_bpp = 8;
#endif
  vdriver_log2_max_bpp = ROMlib_log2[vdriver_max_bpp];
  vdriver_mode_list = &sdl_impotent_modes;

  /* Try for fullscreen on platforms that support it */
  if ( getenv("SDL_FULLSCREEN") != NULL || ROMlib_fullscreen_p )
    video_flags |= SDL_FULLSCREEN;

  /* Allow unsafe fullscreen video memory access */
  if ( getenv("SDL_HWSURFACE") != NULL || ROMlib_hwsurface_p )
    video_flags |= SDL_HWSURFACE;

  /* Clean up on exit */
  atexit(vdriver_shutdown);
  return(TRUE);
}

boolean_t
vdriver_acceptable_mode_p (int width, int height, int bpp,
			   boolean_t grayscale_p, boolean_t exact_match_p)
{
  boolean_t retval;

  if (!width)
    width = vdriver_width;

  if (!height)
    height = vdriver_height;

  if (!bpp)
    bpp = vdriver_bpp;

  if ( ! SDL_VideoModeOK(width, height, bpp, video_flags) )
    retval = FALSE;
  else if ( grayscale_p != vdriver_grayscale_p )
    retval = FALSE;
  else
    retval = bpp <= 8;

  return retval;
}

boolean_t
vdriver_set_mode (int width, int height, int bpp, boolean_t grayscale_p)
{
  /* Massage the width and height parameters */
  if ( width == 0 )
    {
      width = vdriver_width;
      if (width == 0)
	{
	  width = VDRIVER_DEFAULT_SCREEN_WIDTH;
#if 1
#warning "TODO: fixme so we can use fullscreen in Mac OS X"
#else
	  if (ROMlib_fullscreen_p)
	    width = MAX (width, os_current_screen_width ());
#endif
	}
    }

  if ( height == 0 )
    {
      height = vdriver_height;
      if (height == 0)
	{
	  height = VDRIVER_DEFAULT_SCREEN_HEIGHT;
#if 1
#warning "TODO: fixme so we can use fullscreen in Mac OS X"
#else
	  if (ROMlib_fullscreen_p)
	    height = MAX (height, os_current_screen_height ());
#endif
	}
    }

  if ( bpp == 0 )
    bpp = vdriver_bpp;

  if ( ! vdriver_acceptable_mode_p(width, height, bpp, grayscale_p, FALSE) )
    return(FALSE);

  /* Set the video mode */
  screen = SDL_SetVideoMode(width, height, bpp, video_flags);
  if ( screen == NULL )
    return(FALSE);

  /* Fill the vdriver globals */
  vdriver_width = screen->w;
  vdriver_height = screen->h;
  vdriver_bpp = screen->format->BitsPerPixel;
  vdriver_log2_bpp = ROMlib_log2[vdriver_bpp];
  vdriver_row_bytes = screen->pitch;
  if ( SDL_MUSTLOCK(screen) )
    {
      /* WARNING!  This results in surface memory that is unsafe to access! */
      if ( SDL_LockSurface(screen) < 0 )
        return(FALSE);
      vdriver_fbuf = (uint8 *)screen->pixels;
      SDL_UnlockSurface(screen);
      fprintf(stderr, "Warning: Executor performing unsafe video access\n");
    }
  else
      vdriver_fbuf = (uint8 *)screen->pixels;

  sdl_syswm_init();

#if defined(CYGWIN32)
  ROMlib_recenter_window ();
#endif

  return(TRUE);
}

void
vdriver_set_colors (int first_color, int num_colors, const ColorSpec *colors)
{
  int i;
  SDL_Color *sdl_cmap;

  sdl_cmap = (SDL_Color *)alloca(num_colors*sizeof(SDL_Color));
  for ( i=0; i<num_colors; ++i )
    {
      sdl_cmap[i].r = (CW (colors[i].rgb.red)   >> 8);
      sdl_cmap[i].g = (CW (colors[i].rgb.green) >> 8);
      sdl_cmap[i].b = (CW (colors[i].rgb.blue ) >> 8);
    }
  SDL_SetColors(screen, sdl_cmap, first_color, num_colors);
}

void
vdriver_get_colors (int first_color, int num_colors, ColorSpec *colors)
{
  gui_fatal ("`!vdriver_fixed_clut_p' and `vdriver_get_colors ()' called");
}

int
vdriver_update_screen_rects (int num_rects, const vdriver_rect_t *r,
                                                      boolean_t cursor_p)
{
  SDL_Rect *rects;
  int       i;

  rects = (SDL_Rect *)alloca(num_rects*sizeof(SDL_Rect));
  for ( i = 0; i < num_rects; ++i )
    {
      rects[i].x = r[i].left;
      rects[i].w = r[i].right-r[i].left;
      rects[i].y = r[i].top;
      rects[i].h = r[i].bottom-r[i].top;
    }
  SDL_UpdateRects(screen, num_rects, rects);
  return(0);
}

int
vdriver_update_screen (int top, int left, int bottom, int right,
		       boolean_t cursor_p)
{
  SDL_Rect rect;
  
  if (top < 0)
    top = 0;
  if (left < 0)
    left = 0;
  
  if (bottom > vdriver_height)
    bottom = vdriver_height;
  if (right > vdriver_width)
    right = vdriver_width;
  
  rect.x = left;
  rect.w = right-left;
  rect.y = top;
  rect.h = bottom-top;
  SDL_UpdateRects(screen, 1, &rect);

  return(0);
}

void
vdriver_flush_display (void)
{
}

void
vdriver_shutdown (void)
{
  SDL_Quit();
}

/* host functions that should go away */

/* shadow buffer; created on demand */
unsigned char *vdriver_shadow_fbuf = NULL;

void
host_flush_shadow_screen (void)
{
  int top_long, left_long, bottom_long, right_long;

  /* Lazily allocate a shadow screen.  We won't be doing refresh that often,
   * so don't waste the memory unless we need it.  Note: memory never reclaimed
   */
  if (vdriver_shadow_fbuf == NULL)
    {
      vdriver_shadow_fbuf = malloc(vdriver_row_bytes * vdriver_height);
      memcpy (vdriver_shadow_fbuf, vdriver_fbuf, 
                                 vdriver_row_bytes * vdriver_height);
      vdriver_update_screen (0, 0, vdriver_height, vdriver_width, FALSE);
    }
  else if (find_changed_rect_and_update_shadow ((uint32 *) vdriver_fbuf,
						(uint32 *) vdriver_shadow_fbuf,
						(vdriver_row_bytes
						 / sizeof (uint32)),
						vdriver_height,
						&top_long, &left_long,
						&bottom_long, &right_long))
    {
      vdriver_update_screen (top_long, (left_long * 32) >> vdriver_log2_bpp,
			     bottom_long,
			     (right_long * 32) >> vdriver_log2_bpp, FALSE);
    }
}
