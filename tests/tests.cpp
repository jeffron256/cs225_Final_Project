#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "../src/mapMaker.h"
#include "../lib/graph.h"
#include "../lib/edge.h"

using std::cout;
using std::endl;


TEST_CASE("test1") {
    mapMaker UIUCbus;
    vector<vector<string>> tmp = UIUCbus.file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph* g1 = UIUCbus.makeGraph(tmp, m1);
    vector<Vertex> expexcted {"E", "B", "D", "C", "A"};
    vector<Vertex> v;
    v = g1->getVertices();
    for (auto pt: v)
    {
        cout << pt << ", ";
    }
    REQUIRE(v == expexcted);
}
