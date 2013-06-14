MINGW = i486-mingw32-g++
CC = g++
CXXFLAGS = -g -I. -std=c++0x -fPIC
LDFLAGS = -g -lSDL -L "C:\Users\Eric\Documents\programming libraries\SDL-1.2.15\bin" -shared
MINGWFLAGS = -shared -lSDL -Wl,-no-undefined --enable-runtime-psuedo-alloc
SOURCES = Space2D/Point.cpp Space2D/Vector.cpp Space2D/Velocity.cpp \
  GameControl/Events.cpp GameControl/GameLoop.cpp GameControl/App.cpp
OBJECTS = $(SOURCES:.cpp=.o)

#WORKING TITLE
EXECUTABLE = libGameFrame.so

all: $(SOURCES) $(EXECUTABLE)

#build - compile my code
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

dll: $(SOURCES) GameFrame.dll
	
GameFrame.dll: $(OBJECTS)
	$(MINGW) $(MINGWFLAGS) -o $@ $^

.cpp:.o
	$(CC) $(CXXFLAGS) -c -o $@ $<
.PHONY: clean doc

clean:
	rm -f $(OBJECTS)
	
doc: 
	rm -r doc/
	doxygen
