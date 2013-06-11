MINGW = i486-mingw32-g++
CC = g++
CXXFLAGS = -g -I. --std=c++11
LDFLAGS = -g -lSDL -shared
MINGWFLAGS = -shared -lSDL -Wl,-no-undefined --enable-runtime-psuedo-alloc
SOURCES = Space2D/Point.cpp Space2D/Vector.cpp Space2D/Velocity.cpp \
  GameControl/App.cpp GameControl/Events.cpp GameControl/GameLoop.cpp
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
.PHONY: clean

clean:
	rm -f $(OBJECTS)
	
