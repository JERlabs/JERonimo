CC = g++
CXXFLAGS = -g -I. --std=c++11
LDFLAGS = -g -lSDL -shared
SOURCES = Space2D/Point.cpp Space2D/Vector.cpp Space2D/Velocity.cpp \
  GameControl/App.cpp GameControl/Events.cpp GameControl/GameLoop.cpp
OBJECTS = $(SOURCES:.cpp=.o)

#WORKING TITLE
EXECUTABLE = libGameFrame.so

all: $(SOURCES) $(EXECUTABLE)

#build - compile my code
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
  
.cpp:.o
	$(CC) $(CXXFLAGS) -c -o $@ $<
.PHONY: clean

clean:
	rm -f $(OBJECTS)
	
