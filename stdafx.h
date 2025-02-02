#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1

#include <cstdio>
#include <string>
#include <cstdlib>
#include <errno.h>
#include <map>
#include <set>
#include <vector>
#include <array>
#include <utility>
#include <cstdint>
#include <memory>


// WARNING: THIS EXTENSION USES AN ALTERED lice.h, SINCE STANDARD lice.h HIDES SOME FUNCTIONS WHEN LICE_PROVIDED_BY_APP, 
// EVEN THOUGH THOSE FUNCTIONS ARE NOT ACTUALLY PROVIDED BY REAPER.


#define REAPERAPI_IMPLEMENT
//#ifndef LICE_PROVIDED_BY_APP
//#error "LICE_PROVIDED_BY_APP should be defined for entire project (if using command line, add -DLICE_PROVIDED_BY_APP to command)."
//#endif
#define LICE_PROVIDED_BY_APP
#define LICE_FAVOR_SPEED
#include "./WDL/lice/lice.h" // !!!!!!!!!!!!!!!! CUSTOMIZED LICE.H !!!!!!!!!!!!!!!!
#include "./WDL/lice/lice_text.h"
#ifndef SWELL_PROVIDED_BY_APP
#error "SWELL_PROVIDED_BY_APP should be defined for entire project (if using command line, add -DSWELL_PROVIDED_BY_APP to command)."
#endif

// reaper_plugin_functions.h #include's reaper_plugin.h, which in turn #include's either windows.h or swell.h, depending on platform.
// So probably only necessary to #include reaper_plugins_functions.h
#include "reaper_plugin_functions.h" 

// Localization
#define LOCALIZE_IMPORT_PREFIX "js_"
#include "localize-import.h"
#include "localize.h"

#ifdef _WIN32
	//#include <windows.h> //is not necessary
	#include <windowsx.h>
	#include <Shlobj.h>
	//#include <Shlobj_core.h>
	#include <wingdi.h>
	#define WINAPI __stdcall
#elif __linux__
	#include <gtk/gtk.h>
        //#include <png.h>
	#define SWELL_TARGET_GDK // This is important since some parts of swell .h files are only compiled if this flag is set.
	#include "./WDL/swell/swell-internal.h" // For definition of HWND__
	#define WINAPI
#else
	//#define SWELL_TARGET_OSX
	//#define __OBJC__
	//#include "./WDL/swell/swell-internal.h"
	#define WINAPI
#endif

// WARNING: REAPER has a handful of UNDOCUMENTED API functions that are not declared in reaper_plugin_functions.h, so must declare here:
BOOL(WINAPI *CoolSB_GetScrollInfo)(HWND hwnd, int nBar, LPSCROLLINFO lpsi);
int (WINAPI *CoolSB_SetScrollInfo)(HWND hwnd, int nBar, LPSCROLLINFO lpsi, BOOL fRedraw);
int (WINAPI *CoolSB_SetScrollPos)(HWND hwnd, int nBar, int nPos, BOOL fRedraw);
void(*AttachWindowTopmostButton)(HWND hwnd);
void(*AttachWindowResizeGrip)(HWND hwnd);
//BOOL(WINAPI *RemoveXPStyle)(HWND hwnd, int rm); // What does this function do?  Doesn't seem to work.

#include "js_ReaScriptAPI.h"
#include "js_ReaScriptAPI_namespace.h"
#include "js_ReaScriptAPI_vararg.h"
#include "js_ReaScriptAPI_def.h"
