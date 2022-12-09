#include <iostream>

#include "../src/mapMaker.h"
#include "../src/shortestPath.h"

using std::cout;
using std::endl;

int main()
{
    vector<vector<string>> tmp = file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph g1 = makeGraph(tmp, m1);

    //cout << "test dijkstra2:"<< endl;
    vector<vector<string>> tmp1 = file_to_Vec("../data/dijktra_test.csv");
    vector<vector<string>> tmp2 = file_to_Vec("../data/bus_stop_info_weekday.csv");
    map<string, vector<string>> m;
    map<string, vector<string>> m2;
    Graph g = makeGraph(tmp1, m);
    Graph g2 = makeGraph(tmp2, m2);

    /*cout << "BC=" << g2.getTimeInterval("B","C") << ", ";
    cout << "BC=" << g2.getTimeInterval("B","C") << ", ";
    cout << "BC=" << g2.getTimeInterval("B","C") << ", ";
    cout << "BC=" << g2.getTimeInterval("B","C") << ", ";
    cout << "BC=" << g2.getTimeInterval("B","C") << ", "; */

    vector<Vertex> actual1 = BFS(g2, "Transit Plaza", "Penn & Vine");
    vector<Vertex> actual2 = dijkstra(g2, "Transit Plaza", "Penn & Vine");
    cout << "BFS: "<< endl;
    for (auto v: actual1) {
        cout << v << ", ";
    }
    cout << endl;
    cout << "dijkstra:"<< endl;
    for (auto v: actual2) {
        cout << v << ", ";
    }
    cout << endl;
    
}