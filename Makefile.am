ACLOCAL_AMFLAGS = -I m4
lib_LTLIBRARIES = libgameframe.la

Space2D := $(top_srcdir)/Space2D
include Space2D/Makefile.am
GameControl := $(top_srcdir)/GameControl
include GameControl/Makefile.am
libgameframe_la_SOURCES = $(Space2D_src) $(GameControl_src)
nobase_libgameframe_la_HEADERS = $(Space2D_h) $(GameControl_h)
libgameframe_ladir = $(includedir)
