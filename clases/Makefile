CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)


all: prueba0 prueba1 prueba2#utxns.exe
	
#prueba2bis: sha256.h sha256.cpp block.h block.cpp prueba2.cpp \
#	txns_lecture.cpp txns_lecture.h Array.h
#	$(CXX) $(CXXFLAGS) sha256.h sha256.cpp prueba2.cpp block.h \
#	block.cpp txns_lecture.cpp txns_lecture.h Array.h -o prueba2 \
#	 && ./prueba2

prueba2: prueba2.o block.o txns_lecture.o sha256.o
	$(CXX) $(CXXFLAGS) prueba2.o block.o txns_lecture.o sha256.o \
	-o prueba2 && ./prueba2

prueba2.o: prueba2.cpp block.h txns_lecture.h 
	$(CXX) $(CXXFLAGS) -c prueba2.cpp -o prueba2.o

block.o: block.cpp block.h sha256.h txns_lecture.h Array.h
	$(CXX) $(CXXFLAGS) -c block.cpp -o block.o

sha256.o: sha256.cpp sha256.h
	$(CXX) $(CXXFLAGS) -c sha256.cpp -o sha256.o
		
prueba1: prueba1.o txns_lecture.o
	$(CXX) $(CXXFLAGS) prueba1.o txns_lecture.o -o prueba1 && \
	./prueba1

prueba1.o: prueba1.cpp txns_lecture.h Array.h
	$(CXX) $(CXXFLAGS) -c prueba1.cpp -o prueba1.o

txns_lecture.o: txns_lecture.cpp txns_lecture.h Array.h
	$(CXX) $(CXXFLAGS) -c txns_lecture.cpp -o txns_lecture.o

prueba0: prueba0.o 
	$(CXX) $(CXXFLAG) prueba0.o -o prueba0 && ./prueba0

prueba0.o: prueba0.cpp Array.h 
	$(CXX) $(CXXFLAG) -c prueba0.cpp -o prueba0.o
#-c Compile or assemble the source files, but do not link. The linking stage simply is not done. 


#runtest.exe: runtest.cc
#	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc

#test tests: cmdline.exe runtest.exe
#	runtest.exe cmdline.tests

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err
