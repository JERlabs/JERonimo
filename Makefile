CXXFLAGS = -g -I. -std=gnu++0x -fPIC -fPIE
LDFLAGS =  -lSDL -lSDL_image -lSDL_gfx -lm -rpath /usr/local/lib -g
LIBTOOL = libtool --tag=CXX

SOURCES = Space2D/Point.cpp Space2D/Vector.cpp Space2D/Velocity.cpp \
  GameControl/Events.cpp GameControl/GameLoop.cpp GameControl/App.cpp \
  GameControl/DataManager.cpp GameControl/TestEvents.cpp SurfaceX/JustASurf.cpp \
  SurfaceX/OpenSurf.cpp SurfaceX/StaticSurf.cpp SurfaceX/SurfaceX.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBOBJECTS = $(SOURCES:.cpp=.lo)
LIBRARY = libGameFrame.la


all: $(SOURCES) $(LIBRARY)

$(LIBRARY): $(LIBOBJECTS)
	$(LIBTOOL) --mode=link $(CXX) $(LDFLAGS) -o $@ $^

install:
	libtool --mode=install install -c libGameFrame.la /usr/local/lib/libGameFrame.la

%.lo: %.cpp
	$(LIBTOOL) --mode=compile $(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean doc

clean:
	rm -f $(OBJECTS) $(LIBOBJECTS)
	rm -rf Space2D/.libs/ GameControl/.libs/

doc: 
	rm -r doc/
	doxygen
