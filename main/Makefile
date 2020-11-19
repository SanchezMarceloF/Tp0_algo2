CXXARGS  = -g -Wall
CXXFLAGS = -I$(DIR) $(CXXARGS)
DIR =../clases

all: prueba0 prueba1 prueba2#utxns.exe

sha: main.o $(DIR)/sha256.o cmdline.o $(DIR)/txns_lecture.o \
	$(DIR)/block.o
	$(CXX) $(CXXFLAGS) -o sha256 main.o $(DIR)/sha256.o \
	cmdline.o $(DIR)/txns_lecture.o $(DIR)/block.o

main.o: main.cpp $(DIR)/sha256.h cmdline.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 

cmdline.o: cmdline.cc cmdline.h
	$(CXX) $(CXXFLAGS) -c cmdline.cc -o cmdline.o 
	
prueba2: $(DIR)prueba2.o block.o $(DIR)txns_lecture.o $(DIR)sha256.o
	$(CXX) $(CXXFLAGS) $(DIR)prueba2.o $(DIR)block.o $(DIR)txns_lecture.o $(DIR)sha256.o \
	-o prueba2 && ./prueba2

prueba2.o: $(DIR)prueba2.cpp $(DIR)block.h $(DIR)txns_lecture.h 
	$(CXX) $(CXXFLAGS) -c $(DIR)prueba2.cpp -o $(DIR)prueba2.o

$(DIR)/block.o: $(DIR)/block.cpp $(DIR)/block.h $(DIR)/sha256.h \
	$(DIR)/txns_lecture.h $(DIR)/Array.h
	$(CXX) $(CXXFLAGS) -c $(DIR)/block.cpp -o $(DIR)/block.o

$(DIR)/sha256.o: $(DIR)/sha256.cpp $(DIR)/sha256.h
	$(CXX) $(CXXFLAGS) -c $(DIR)/sha256.cpp -o $(DIR)/sha256.o
		
prueba1: $(DIR)prueba1.o $(DIR)txns_lecture.o
	$(CXX) $(CXXFLAGS) $(DIR)prueba1.o $(DIR)txns_lecture.o -o prueba1 && \
	./prueba1

$(DIR)prueba1.o: $(DIR)prueba1.cpp $(DIR)txns_lecture.h $(DIR)Array.h
	$(CXX) $(CXXFLAGS) -c $(DIR)prueba1.cpp -o $(DIR)prueba1.o

$(DIR)/txns_lecture.o: $(DIR)/txns_lecture.cpp $(DIR)/txns_lecture.h \
	 $(DIR)/Array.h
	$(CXX) $(CXXFLAGS) -c $(DIR)/txns_lecture.cpp \
	-o $(DIR)/txns_lecture.o

prueba0: $(DIR)prueba0.o 
	$(CXX) $(CXXFLAG) $(DIR)prueba0.o -o prueba0 && ./prueba0

$(DIR)prueba0.o: $(DIR)prueba0.cpp $(DIR)Array.h 
	$(CXX) $(CXXFLAG) -c $(DIR)prueba0.cpp -o $(DIR)prueba0.o
#-c Compile or assemble the source files, but do not link. The linking stage simply is not done. 


#runtest.exe: runtest.cc
#	$(CXX) $(CXXFLAGS) -o runtest.exe runtest.cc

#test tests: cmdline.exe runtest.exe
#	runtest.exe cmdline.tests

clean:
	$(RM) -vf *.o *.exe *.t *.out *.err
