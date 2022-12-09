#include <iostream>

#include "../src/mapMaker.h"
#include "../src/shortestPath.h"

using std::cout;
using std::endl;

int main()
{
    mapMaker UIUCbus;
    vector<vector<string>> tmp = UIUCbus.file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph g1 = UIUCbus.makeGraph(tmp, m1);

    cout << "test dijkstra2:"<< endl;
    mapMaker U;
    vector<vector<string>> tmp1 = U.file_to_Vec("../data/dijktra_test.csv");
    map<string, vector<string>> m;
    Graph g = U.makeGraph(tmp1, m);
    vector<Vertex> actual2 = BFS(g, "A", "H");
    vector<Vertex> expected2 = vector<Vertex> {"A","F","E","H"};
    cout << "2: "<< endl;
    for (auto v: actual2) {
        cout << v << "\t";
    }
    cout << endl;
    
}