CXX      := g++
CXXFLAGS := -g

OBJS := main.o puzzle.o
BIN  := cpp15puzzle

DEL := rm -f

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(BIN) $(OBJS)

main.o   : puzzle.h
puzzle.o : puzzle.h Random.h

clean:
	@for item in $(OBJS);\
	    do if [ -f $$item ]; then $(DEL) $$item; fi;\
	done
	@if [ -f $(BIN) ]; then $(DEL) $(BIN); fi
