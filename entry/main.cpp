#include <iostream>

#include "../src/mapMaker.h"

using std::cout;
using std::endl;

int main()
{
    mapMaker UIUCbus;
    vector<vector<string>> tmp = UIUCbus.file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph* g1 = UIUCbus.makeGraph(tmp, m1);
    cout << "expected: " << endl;
    cout << "vertex : E, B, D, C, A" << '\n'<< endl;
    cout << "edge : AB=1, BC=3, DC=1, BD=1, CE=2, EB=1" << endl;
    cout << '\n';
    cout << "actual: " << endl;
    cout << "vertex : ";
    vector<Vertex> v;
    v = g1->getVertices();
    for (auto pt: v)
    {
        cout << pt << ", ";
    }
    cout << "\n\n" << "edge: AB=" << g1->getTimeInterval("A","B") << ", ";
    cout << "BC=" << g1->getTimeInterval("B","C") << ", ";
    cout << "DC=" << g1->getTimeInterval("D","C") << ", ";
    cout << "BD=" << g1->getTimeInterval("B","D") << ", ";
    cout << "CE=" << g1->getTimeInterval("C","E") << ", ";
    cout << "EB=" << g1->getTimeInterval("E","B") << endl;
}