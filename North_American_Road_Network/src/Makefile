EXENAME = main 
OBJS = main.o Graph.o Utils.o data225.o tests.o 

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: main.cpp 
	$(CXX) $< $(CXXFLAGS)

tests.o: tests.cpp	
	$(CXX) $< $(CXXFLAGS)

data225.o: data225.cpp	
	$(CXX) $< $(CXXFLAGS)

Graph.o: Graph.cpp
	$(CXX) $< $(CXXFLAGS)
	
Utils.o: Utils.cpp	
	$(CXX) $< $(CXXFLAGS)

clean: 
	-rm -f *.o $(EXENAME)
