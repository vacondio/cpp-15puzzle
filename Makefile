CXX      := g++
CXXFLAGS := -g -std=c++20

OBJS := main.o input_handler.o puzzle.o
BIN  := cpp15puzzle.x

DEL := rm -f

$(BIN) : $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(BIN) $(OBJS)

main.o   : input_handler.h puzzle.h
input_handler.o : input_handler.h
puzzle.o : puzzle.h Random.h

clean:
	@for item in $(OBJS);\
	    do if [ -f $$item ]; then $(DEL) $$item; fi;\
	done
	@if [ -f $(BIN) ]; then $(DEL) $(BIN); fi
