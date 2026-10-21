CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test logicsim-exe

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o llrec-test

logicsim-exe: logicsim/logicsim.cpp logicsim/circuit.cpp logicsim/gate.cpp logicsim/wire.cpp
	$(CXX) $(CXXFLAGS) logicsim/logicsim.cpp logicsim/circuit.cpp logicsim/gate.cpp logicsim/wire.cpp -o logicsim-exe
clean:
	rm -f *.o rh llrec-test logicsim-exe *~

.PHONY: clean 