CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Dungeon.cpp Feature.cpp Inventory.cpp Parser.cpp Player.cpp Room.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm *o main