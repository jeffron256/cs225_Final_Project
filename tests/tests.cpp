#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "../src/mapMaker.h"
#include "../lib/graph.h"
#include "../lib/edge.h"
#include "../src/shortestPath.h"

using std::cout;
using std::endl;


TEST_CASE("makegraph") {
    vector<vector<string>> tmp = file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph g1 = makeGraph(tmp, m1);
    vector<Vertex> expexcted {"E", "B", "D", "C", "A"};
    vector<Vertex> v;
    v = g1.getVertices();
    for (auto pt: v)
    {
        cout << pt << ", ";
    }
    REQUIRE(v == expexcted);
}


TEST_CASE("dijkstra simple") {
    vector<vector<string>> tmp = file_to_Vec("../data/test_make_graph_small.csv");
    map<string, vector<string>> m1;
    Graph g1 = makeGraph(tmp, m1);
    vector<Vertex> expected {"A", "B", "E"};
    vector<Vertex> actual = dijkstra(g1, "A", "E");
    REQUIRE(actual == expected);
}

TEST_CASE("dijkstra medium") {
    vector<vector<string>> tmp1 = file_to_Vec("../data/dijktra_test.csv");
    map<string, vector<string>> m;
    Graph g = makeGraph(tmp1, m);
    vector<Vertex> actual1 = dijkstra(g, "A", "E");
    vector<Vertex> expected1 = vector<Vertex> {"A","F","E"};
    vector<Vertex> actual2 = dijkstra(g, "A", "H");
    vector<Vertex> expected2 = vector<Vertex> {"A","F","E","H"};
    REQUIRE(actual1 == expected1);
    REQUIRE(actual2 == expected2);
}