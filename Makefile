EXEC=astres
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
CC=g++ -std=c++11 -g
LDFLAGS=-lsfml-graphics  -lsfml-window -lsfml-system
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS)  -o $(EXEC)
%.o: %.cc
	$(CC) -Wall -c $< -o $@

.depend: $(SOURCES)
	g++ -std=c++11 -MM $(SOURCES) > .depend
-include .depend
clean:
	rm -f $(OBJECTS) $(EXEC)
