# NMake Makefile portion for enabling features for Windows builds

# These are the base minimum libraries required for building glibmm.
BASE_INCLUDES =	/I$(PREFIX)\include

# Please do not change anything beneath this line unless maintaining the NMake Makefiles
GLIB_API_VERSION = 2.0

GLIBMM_MAJOR_VERSION = 2
GLIBMM_MINOR_VERSION = 4

LIBSIGC_MAJOR_VERSION = 2
LIBSIGC_MINOR_VERSION = 0

!if "$(CFG)" == "debug" || "$(CFG)" == "Debug"
DEBUG_SUFFIX = -d
!else
DEBUG_SUFFIX =
!endif

!ifndef M4
M4 = m4
!endif

GLIBMM_BASE_CFLAGS =			\
	/Ivs$(VSVER)\$(CFG)\$(PLAT)	\
	/I..\untracked\glib /I..\untracked\glib\glibmm		\
	/I..\glib /I..\glib\glibmm /I.\glibmm /EHsc	\
	/FImsvc_recommended_pragmas.h

GIOMM_BASE_CFLAGS =	\
	/Ivs$(VSVER)\$(CFG)\$(PLAT)	\
	/I..\untracked\gio /I..\untracked\gio\giomm	\
	/I..\gio /I..\gio\giomm /I.\giomm	\
	$(GLIBMM_BASE_CFLAGS)

GLIBMM_EXTRA_INCLUDES =	\
	/I$(PREFIX)\include\gio-win32-$(GLIB_API_VERSION)	\
	/I$(PREFIX)\include\glib-$(GLIB_API_VERSION)	\
	/I$(PREFIX)\lib\glib-$(GLIB_API_VERSION)\include	\
	/I$(PREFIX)\include\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)	\
	/I$(PREFIX)\lib\sigc++-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)\include

LIBGLIBMM_CFLAGS = /DGLIBMM_BUILD /DSIZEOF_WCHAR_T=2 $(GLIBMM_BASE_CFLAGS) $(GLIBMM_EXTRA_INCLUDES)
LIBGIOMM_CFLAGS = /DGIOMM_BUILD /DSIZEOF_WCHAR_T=2 $(GIOMM_BASE_CFLAGS) $(GLIBMM_EXTRA_INCLUDES)
GLIBMM_EX_CFLAGS = $(GLIBMM_BASE_CFLAGS) $(GLIBMM_EXTRA_INCLUDES)
GIOMM_EX_CFLAGS = $(GIOMM_BASE_CFLAGS) $(GLIBMM_EXTRA_INCLUDES)

# We build glibmm-vc$(VSVER_LIB)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION).dll or
#          glibmm-vc$(VSVER_LIB)-d-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION).dll at least
#          giomm-vc$(VSVER_LIB)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION).dll or
#          giomm-vc$(VSVER_LIB)-d-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION).dll at least

!if "$(USE_COMPAT_LIBS)" != ""
VSVER_LIB = $(PDBVER)0
MESON_VSVER_LIB =
!else
VSVER_LIB = $(PDBVER)$(VSVER_SUFFIX)
MESON_VSVER_LIB = -vc$(VSVER_LIB)
!endif

!ifdef USE_MESON_LIBS
LIBSIGC_LIBNAME = sigc-$(LIBSIGC_MAJOR_VERSION).$(LIBSIGC_MINOR_VERSION)
GLIBMM_LIBNAME = glibmm$(MESON_VSVER_LIB)-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)
GIOMM_LIBNAME = giomm$(MESON_VSVER_LIB)-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)
GLIBMM_EXTRA_DEFS_GEN_LIBNAME = glibmm_generate_extra_defs-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)

GLIBMM_DLLNAME = $(GLIBMM_LIBNAME)-1
GIOMM_DLLNAME = $(GIOMM_LIBNAME)-1
GLIBMM_EXTRA_DEFS_GEN_DLLNAME = $(GLIBMM_EXTRA_DEFS_GEN_LIBNAME)-1
!else
LIBSIGC_LIBNAME = sigc-vc$(PDBVER)0$(DEBUG_SUFFIX)-$(LIBSIGC_MAJOR_VERSION)_$(LIBSIGC_MINOR_VERSION)
GLIBMM_LIBNAME = glibmm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION)
GIOMM_LIBNAME = giomm-vc$(VSVER_LIB)$(DEBUG_SUFFIX)-$(GLIBMM_MAJOR_VERSION)_$(GLIBMM_MINOR_VERSION)
GLIBMM_EXTRA_DEFS_GEN_LIBNAME = glibmm_generate_extra_defs-$(GLIBMM_MAJOR_VERSION).$(GLIBMM_MINOR_VERSION)

GLIBMM_DLLNAME = $(GLIBMM_LIBNAME)
GIOMM_DLLNAME = $(GIOMM_LIBNAME)
GLIBMM_EXTRA_DEFS_GEN_DLLNAME = $(GLIBMM_EXTRA_DEFS_GEN_LIBNAME)
!endif

LIBSIGC_LIB = $(LIBSIGC_LIBNAME).lib

GLIBMM_DLL = vs$(VSVER)\$(CFG)\$(PLAT)\$(GLIBMM_DLLNAME).dll
GLIBMM_LIB = vs$(VSVER)\$(CFG)\$(PLAT)\$(GLIBMM_LIBNAME).lib
GIOMM_DLL = vs$(VSVER)\$(CFG)\$(PLAT)\$(GIOMM_DLLNAME).dll
GIOMM_LIB = vs$(VSVER)\$(CFG)\$(PLAT)\$(GIOMM_LIBNAME).lib
GLIBMM_EXTRA_DEFS_GEN_DLL = vs$(VSVER)\$(CFG)\$(PLAT)\$(GLIBMM_EXTRA_DEFS_GEN_DLLNAME).dll
GLIBMM_EXTRA_DEFS_GEN_LIB = vs$(VSVER)\$(CFG)\$(PLAT)\$(GLIBMM_EXTRA_DEFS_GEN_LIBNAME).lib

GOBJECT_LIBS = gobject-2.0.lib gmodule-2.0.lib glib-2.0.lib
GIO_LIBS = gio-2.0.lib $(GOBJECT_LIBS)

GLIBMM_EX_LIBS = $(GLIBMM_LIB) $(LIBSIGC_LIB) $(GOBJECT_LIBS)
GIOMM_EX_LIBS = $(GIOMM_LIB) $(GLIBMM_LIB) $(LIBSIGC_LIB) $(GIO_LIBS)

# Set a default location for glib-compile-schemas, if not specified
!ifndef GLIB_COMPILE_SCHEMAS
GLIB_COMPILE_SCHEMAS = $(PREFIX)\bin\glib-compile-schemas
!endif