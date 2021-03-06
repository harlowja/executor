#ifndef OPENSTEP

#import <appkit/View.h>
#import <appkit/NXImage.h>
#import <appkit/NXImageRep.h>
#import <appkit/NXBitmapImageRep.h>
#import <dpsclient/dpsNeXT.h>

#else /* OPENSTEP */

#import <AppKit/NSView.h>
#import <AppKit/NSImage.h>
#import <AppKit/NSImageRep.h>
#import <AppKit/NSBitmapImageRep.h>

#endif /* OPENSTEP */

/* Artifical mappings */
#define MACCHAR_THORN			161
#define MACCHAR_ONEHALF			173
#define MACCHAR_ONESUPERIOR		176
#define MACCHAR_THREESUPERIOR		178
#define MACCHAR_BROKENBAR		179
#define MACCHAR_eTH			182
#define MACCHAR_tHORN			183
#define MACCHAR_yACUTE			184
#define MACCHAR_LSLASH			185
#define MACCHAR_TWOSUPERIOR		186
#define MACCHAR_THREEQUARTERS		189
#define MACCHAR_lSLASH			195
#define MACCHAR_YACUTE			197
#define MACCHAR_MULTIPLY		198
#define MACCHAR_ONEQUARTER		215
#define MACCHAR_ETH			240
#define MACCHAR_NEXT254			170
#define MACCHAR_NEXT255			217
/* real mappings */
#define MACCHAR_QUOTESINGLE             39
#define MACCHAR_GRAVE                   96
#define MACCHAR_ADIERESIS		128
#define MACCHAR_ARING			129
#define MACCHAR_CCEDILLA		130
#define MACCHAR_EACUTE			131
#define MACCHAR_NTILDE			132
#define MACCHAR_ODIERESIS		133
#define MACCHAR_UDIERESIS		134
#define MACCHAR_aACUTE			135
#define MACCHAR_aGRAVE			136
#define MACCHAR_aCIRCUMFLEX		137
#define MACCHAR_aDIERESIS		138
#define MACCHAR_aTILDE			139
#define MACCHAR_aRING			140
#define MACCHAR_cCEDILLA		141
#define MACCHAR_eACUTE			142
#define MACCHAR_eGRAVE			143
#define MACCHAR_eCIRCUMFLEX		144
#define MACCHAR_eDIERESIS		145
#define MACCHAR_iACUTE			146
#define MACCHAR_iGRAVE			147
#define MACCHAR_iCIRCUMFLEX		148
#define MACCHAR_iDIERESIS		149
#define MACCHAR_nTILDE			150
#define MACCHAR_oACUTE			151
#define MACCHAR_oGRAVE			152
#define MACCHAR_oCIRCUMFLEX		153
#define MACCHAR_oDIERESIS		154
#define MACCHAR_oTILDE			155
#define MACCHAR_uACUTE			156
#define MACCHAR_uGRAVE			157
#define MACCHAR_uCIRCUMFLEX		158
#define MACCHAR_uDIERESIS		159
#define MACCHAR_DAGGER			160
#define MACCHAR_DEGREE			161
#define MACCHAR_CENT			162
#define MACCHAR_STERLING		163
#define MACCHAR_SECTION			164
#define MACCHAR_BULLET			165
#define MACCHAR_PARAGRAPH		166
#define MACCHAR_GERMANDBLS		167
#define MACCHAR_REGISTERED		168
#define MACCHAR_COPYRIGHT		169
#define MACCHAR_TRADEMARK		170
#define MACCHAR_ACUTE			171
#define MACCHAR_DIERESIS		172
#define MACCHAR_NOTEQUAL		173
#define MACCHAR_AE			174
#define MACCHAR_OSLASH			175
#define MACCHAR_INFINITY		176
#define MACCHAR_PLUSMINUS		177
#define MACCHAR_LESSEQUAL		178
#define MACCHAR_GREATEQUAL		179
#define MACCHAR_YEN			180
#define MACCHAR_MU			181
#define MACCHAR_PARTIALDIFF		182
#define MACCHAR_SUMMATION		183
#define MACCHAR_PRODUCT			184
#define MACCHAR_PI			185
#define MACCHAR_INTEGRAL		186
#define MACCHAR_ORDFEMININE		187
#define MACCHAR_ORDMASCULINE		188
#define MACCHAR_OMEGA			189
#define MACCHAR_ae			190
#define MACCHAR_oSLASH			191
#define MACCHAR_QUESTIONDOWN		192
#define MACCHAR_EXCLAMDOWN		193
#define MACCHAR_LOGICALNOT		194
#define MACCHAR_RADICAL			195
#define MACCHAR_FLORIN			196
#define MACCHAR_APPROXEQUAL		197
#define MACCHAR_DELTA			198
#define MACCHAR_GUILLEMOTLEFT		199
#define MACCHAR_GUILLEMOTRIGHT		200
#define MACCHAR_ELLIPSIS		201
#define MACCHAR_FIGSP			202	/* No-break space */
#define MACCHAR_AGRAVE			203
#define MACCHAR_ATILDE			204
#define MACCHAR_OTILDE			205
#define MACCHAR_OE			206
#define MACCHAR_oe			207
#define MACCHAR_ENDASH			208
#define MACCHAR_EMDASH			209
#define MACCHAR_QUOTEDBLLEFT		210
#define MACCHAR_QUOTEDBLRIGHT		211
#define MACCHAR_QUOTELEFT		212	/* 96 on the NeXT */
#define MACCHAR_QUOTERIGHT		213	/* 39 on the NeXT */
#define MACCHAR_DIVIDE			214
#define MACCHAR_LOZENGE			215
#define MACCHAR_yDIERESIS		216
#define MACCHAR_YDIERESIS		217
#define MACCHAR_FRACTION		218
#define MACCHAR_CURRENCY		219
#define MACCHAR_GUILSINGLLEFT		220
#define MACCHAR_GUILSINGLRIGHT		221
#define MACCHAR_FI			222
#define MACCHAR_FL			223
#define MACCHAR_DAGGERDBL		224
#define MACCHAR_PERIODCENTERED		225
#define MACCHAR_QUOTESINGLBASE		226
#define MACCHAR_QUOTEDBLBASE		227
#define MACCHAR_PERTHOUSAND		228
#define MACCHAR_ACIRCUMFLEX		229
#define MACCHAR_ECIRCUMFLEX		230
#define MACCHAR_AACUTE			231
#define MACCHAR_EDIERESIS		232
#define MACCHAR_EGRAVE			233
#define MACCHAR_IACUTE			234
#define MACCHAR_ICIRCUMFLEX		235
#define MACCHAR_IDIERESIS		236
#define MACCHAR_IGRAVE			237
#define MACCHAR_OACUTE			238
#define MACCHAR_OCIRCUMFLEX		239
#define MACCHAR_APPLE			240
#define MACCHAR_OGRAVE			241
#define MACCHAR_UACUTE			242
#define MACCHAR_UCIRCUMFLEX		243
#define MACCHAR_UGRAVE			244
#define MACCHAR_DOTLESSI		245
#define MACCHAR_CIRCUMFLEX		246
#define MACCHAR_TILDE			247
#define MACCHAR_MACRON			248
#define MACCHAR_BREVE			249
#define MACCHAR_DOTACCENT		250
#define MACCHAR_RING			251
#define MACCHAR_CEDILLA			252
#define MACCHAR_HUNGARUMLAUT		253
#define MACCHAR_OGONEK			254
#define MACCHAR_CARON			255
/* artificial mappings */
#define NEXTCHAR_APPLE    		144
#define NEXTCHAR_APPROXEQUAL    	155
#define NEXTCHAR_DEGREE         	156
#define NEXTCHAR_DELTA          	158
#define NEXTCHAR_GREATEQUAL     	181
#define NEXTCHAR_INFINITY       	192
#define NEXTCHAR_INTEGRAL       	201
#define NEXTCHAR_LESSEQUAL      	204
#define NEXTCHAR_LOZENGE        	210
#define NEXTCHAR_NOTEQUAL       	211
#define NEXTCHAR_OMEGA          	212
#define NEXTCHAR_PARTIALDIFF    	230
#define NEXTCHAR_PI             	232
#define NEXTCHAR_PRODUCT        	247
#define NEXTCHAR_RADICAL        	248
#define NEXTCHAR_SUMMATION      	252
#define NEXTCHAR_TRADEMARK      	254
#define NEXTCHAR_YDIERESIS      	255
/* real mappings */
#define NEXTCHAR_QUOTERIGHT             39
#define NEXTCHAR_QUOTELEFT              96
#define NEXTCHAR_FIGSP			128
#define NEXTCHAR_AGRAVE			129
#define NEXTCHAR_AACUTE			130
#define NEXTCHAR_ACIRCUMFLEX		131
#define NEXTCHAR_ATILDE			132
#define NEXTCHAR_ADIERESIS		133
#define NEXTCHAR_ARING			134
#define NEXTCHAR_CCEDILLA		135
#define NEXTCHAR_EGRAVE			136
#define NEXTCHAR_EACUTE			137
#define NEXTCHAR_ECIRCUMFLEX		138
#define NEXTCHAR_EDIERESIS		139
#define NEXTCHAR_IGRAVE			140
#define NEXTCHAR_IACUTE			141
#define NEXTCHAR_ICIRCUMFLEX		142
#define NEXTCHAR_IDIERESIS		143
#define NEXTCHAR_ETH			144
#define NEXTCHAR_NTILDE			145
#define NEXTCHAR_OGRAVE			146
#define NEXTCHAR_OACUTE			147
#define NEXTCHAR_OCIRCUMFLEX		148
#define NEXTCHAR_OTILDE			149
#define NEXTCHAR_ODIERESIS		150
#define NEXTCHAR_UGRAVE			151
#define NEXTCHAR_UACUTE			152
#define NEXTCHAR_UCIRCUMFLEX		153
#define NEXTCHAR_UDIERESIS		154
#define NEXTCHAR_YACUTE			155
#define NEXTCHAR_THORN			156
#define NEXTCHAR_MU			157
#define NEXTCHAR_MULTIPLY		158
#define NEXTCHAR_DIVIDE			159
#define NEXTCHAR_COPYRIGHT		160
#define NEXTCHAR_EXCLAMDOWN		161
#define NEXTCHAR_CENT			162
#define NEXTCHAR_STERLING		163
#define NEXTCHAR_FRACTION		164
#define NEXTCHAR_YEN			165
#define NEXTCHAR_FLORIN			166
#define NEXTCHAR_SECTION		167
#define NEXTCHAR_CURRENCY		168
#define NEXTCHAR_QUOTESINGLE		169	/* 39 on the mac */
#define NEXTCHAR_QUOTEDBLLEFT		170
#define NEXTCHAR_GUILLEMOTLEFT		171
#define NEXTCHAR_GUILSINGLLEFT		172
#define NEXTCHAR_GUILSINGLRIGHT		173
#define NEXTCHAR_FI			174
#define NEXTCHAR_FL			175
#define NEXTCHAR_REGISTERED		176
#define NEXTCHAR_ENDASH			177
#define NEXTCHAR_DAGGER			178
#define NEXTCHAR_DAGGERDBL		179
#define NEXTCHAR_PERIODCENTERED		180
#define NEXTCHAR_BROKENBAR		181
#define NEXTCHAR_PARAGRAPH		182
#define NEXTCHAR_BULLET			183
#define NEXTCHAR_QUOTESINGLBASE		184
#define NEXTCHAR_QUOTEDBLBASE		185
#define NEXTCHAR_QUOTEDBLRIGHT		186
#define NEXTCHAR_GUILLEMOTRIGHT		187
#define NEXTCHAR_ELLIPSIS		188
#define NEXTCHAR_PERTHOUSAND		189
#define NEXTCHAR_LOGICALNOT		190
#define NEXTCHAR_QUESTIONDOWN		191
#define NEXTCHAR_ONESUPERIOR		192
#define NEXTCHAR_GRAVE			193	/* 96 on the mac */
#define NEXTCHAR_ACUTE			194
#define NEXTCHAR_CIRCUMFLEX		195
#define NEXTCHAR_TILDE			196
#define NEXTCHAR_MACRON			197
#define NEXTCHAR_BREVE			198
#define NEXTCHAR_DOTACCENT		199
#define NEXTCHAR_DIERESIS		200
#define NEXTCHAR_TWOSUPERIOR		201
#define NEXTCHAR_RING			202
#define NEXTCHAR_CEDILLA		203
#define NEXTCHAR_THREESUPERIOR		204
#define NEXTCHAR_HUNGARUMLAUT		205
#define NEXTCHAR_OGONEK			206
#define NEXTCHAR_CARON			207
#define NEXTCHAR_EMDASH			208
#define NEXTCHAR_PLUSMINUS		209
#define NEXTCHAR_ONEQUARTER		210
#define NEXTCHAR_ONEHALF		211
#define NEXTCHAR_THREEQUARTERS		212
#define NEXTCHAR_aGRAVE			213
#define NEXTCHAR_aACUTE			214
#define NEXTCHAR_aCIRCUMFLEX		215
#define NEXTCHAR_aTILDE			216
#define NEXTCHAR_aDIERESIS		217
#define NEXTCHAR_aRING			218
#define NEXTCHAR_cCEDILLA		219
#define NEXTCHAR_eGRAVE			220
#define NEXTCHAR_eACUTE			221
#define NEXTCHAR_eCIRCUMFLEX		222
#define NEXTCHAR_eDIERESIS		223
#define NEXTCHAR_iGRAVE			224
#define NEXTCHAR_AE			225
#define NEXTCHAR_iACUTE			226
#define NEXTCHAR_ORDFEMININE		227
#define NEXTCHAR_iCIRCUMFLEX		228
#define NEXTCHAR_iDIERESIS		229
#define NEXTCHAR_eTH			230
#define NEXTCHAR_nTILDE			231
#define NEXTCHAR_LSLASH			232
#define NEXTCHAR_OSLASH			233
#define NEXTCHAR_OE			234
#define NEXTCHAR_ORDMASCULINE		235
#define NEXTCHAR_oGRAVE			236
#define NEXTCHAR_oACUTE			237
#define NEXTCHAR_oCIRCUMFLEX		238
#define NEXTCHAR_oTILDE			239
#define NEXTCHAR_oDIERESIS		240
#define NEXTCHAR_ae			241
#define NEXTCHAR_uGRAVE			242
#define NEXTCHAR_uACUTE			243
#define NEXTCHAR_uCIRCUMFLEX		244
#define NEXTCHAR_DOTLESSI		245
#define NEXTCHAR_uDIERESIS		246
#define NEXTCHAR_yACUTE			247
#define NEXTCHAR_lSLASH			248
#define NEXTCHAR_oSLASH			249
#define NEXTCHAR_oe			250
#define NEXTCHAR_GERMANDBLS		251
#define NEXTCHAR_tHORN			252
#define NEXTCHAR_yDIERESIS		253

#ifndef OPENSTEP
#import <appkit/appkit.h>
#else /* OPENSTEP */
#import <AppKit/AppKit.h>
#endif /* OPENSTEP */

#ifndef OPENSTEP
@interface MacViewClass:View 
#else /* OPENSTEP */
@interface MacViewClass:NSView 
#endif /* OPENSTEP */
{
}

- step;
#ifndef OPENSTEP
- initFrame:(const NXRect *)frm;
#endif /* not OPENSTEP */
- (BOOL)acceptsFirstMouse;
- (BOOL) acceptsFirstResponder;
#ifndef OPENSTEP
- sizeTo:(NXCoord) width :(NXCoord)height;
- mouseDown:(NXEvent *)eventp;
- mouseMoved:(NXEvent *)eventp;
- mouseUp:(NXEvent *)eventp;
- keyDown:(NXEvent *)eventp;
- keyUp:(NXEvent *)eventp;
- drawSelf:(const NXRect *)rects :(int)rectCount ;
- validRequestorForSendType:(NXAtom)typeSent
					    andReturnType:(NXAtom)typeReturned;
- readSelectionFromPasteboard:pboard;
- (BOOL)writeSelectionToPasteboard:pboard types:(NXAtom *)types;
- (BOOL)getRect:(NXRect *)theRect forPage:(int)page;
#else /* OPENSTEP */
- (void) mouseDown:(NSEvent *)eventp;
- (void) mouseMoved:(NSEvent *)eventp;
- (void) mouseUp:(NSEvent *)eventp;
- (void) keyDown:(NSEvent *)eventp;
- (void) keyUp:(NSEvent *)eventp;
- (void) readSelectionFromPasteboard:pboard;
#endif /* OPENSTEP */
- (BOOL)knowsPagesFirst:(int *)firstPageNum last:(int *)lastPageNum;
#ifndef OPENSTEP
- beginPageSetupRect:(const NXRect  * )aRect
					  placement:(const NXPoint *) location;
- endPage;
- endPSOutput;
- pause:sender;
- abort:sender;
- mailARDI:sender;
- (void) installinfo:(const char *)name :(const char *) version;
#else /* OPENSTEP */
- (void) beginPageSetupRect:(NSRect)aRect placement:(NSPoint) location;
- (void) endPage;
- (void) pause:sender;
- (void) abort:sender;
#endif /* OPENSTEP */

@end
