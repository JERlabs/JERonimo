CXXFLAGS = -g -I. -std=c++0x -fPIC -fPIE
LDFLAGS = -lSDL -lm -rpath /usr/local/lib
LIBTOOL = libtool

SOURCES = Space2D/Point.cpp Space2D/Vector.cpp Space2D/Velocity.cpp \
  GameControl/Events.cpp GameControl/GameLoop.cpp GameControl/App.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBOBJECTS = $(SOURCES:.cpp=.lo)
LIBRARY = libGameFrame.la


all: $(SOURCES) $(LIBRARY)

$(LIBRARY): $(LIBOBJECTS)
	$(LIBTOOL) --mode=link $(CXX) $(LDFLAGS) -o $@ $^

%.lo: %.cpp
	$(LIBTOOL) --mode=compile $(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean doc

clean:
	rm -f $(OBJECTS) $(LIBOBJECTS)
	rm -rf Space2D/.libs/ GameControl/.libs/

doc: 
	rm -r doc/
	doxygen
