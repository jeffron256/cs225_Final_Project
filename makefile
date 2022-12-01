EXENAME = main
# OBJS = main.o Graph.o
OBJS = main.o mapMaker.o graph.o shortestPath.o
OBJS_DIR = .objs

CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: entry/main.cpp
	$(CXX) $< $(CXXFLAGS)

graph.o: lib/graph.cc lib/graph.h
	$(CXX) $< $(CXXFLAGS)

mapMaker.o: src/mapMaker.cc src/mapMaker.h
	$(CXX) $< $(CXXFLAGS)

shortestPath.o: src/shortestPath.cc src/shortestPath.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)