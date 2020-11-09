CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)


all: prueba0 prueba1 #utxns.exe
	
prueba1: prueba1.cpp txns_lecture.cpp txns_lecture.h Array.h
	$(CXX) $(CXXFLAGS) prueba1.cpp txns_lecture.cpp txns_lecture.h Array.h -o prueba1 && ./prueba1

prueba0: prueba0.cpp Array.h
	$(CXX) $(CXXFLAGS) prueba0.cpp Array.h -o prueba0 && ./prueba0

#runtest.exe: runtest.cc
#	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc

#test tests: cmdline.exe runtest.exe
#	runtest.exe cmdline.tests

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err
