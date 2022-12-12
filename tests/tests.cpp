#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <algorithm>

#include "../src/mapMaker.h"
#include "../lib/graph.h"
#include "../lib/edge.h"
#include "../src/shortestPath.h"

TEST_CASE("makeGraph Simple Test 1", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_small.csv");

    const std::vector<Vertex> expected {"A", "B", "C", "D", "E"};

    std::vector<Vertex> actual_vertices = g.getVertices();
    std::sort(actual_vertices.begin(), actual_vertices.end());
    REQUIRE(actual_vertices == expected);
}

TEST_CASE("makeGraph Simple Test 2", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_2.csv");

    REQUIRE(!g.edgeExists("H", "F"));
    REQUIRE(g.edgeExists("F", "G"));
    REQUIRE(g.edgeExists("D", "A"));

    const std::vector<Vertex> expected {"A", "B", "C", "D", "E", "F", "G", "H"};

    std::vector<Vertex> actual_vertices = g.getVertices();
    std::sort(actual_vertices.begin(), actual_vertices.end());
    REQUIRE(actual_vertices == expected);
}

TEST_CASE("makeGraph Hard Test 1", "[weight=5]") {
    Graph g = init("../tests/test_make_graph_3.csv");
    
    REQUIRE(g.edgeExists("Illinois Terminal", "Logan & First"));
    REQUIRE(g.edgeExists("Plant Sciences Lab", "Pennsylvania at Par"));
    REQUIRE(g.edgeExists("Lincoln & St. Mary's", "Lincoln at Japan House"));

    std::string actual_line = g.getBusLine("Mtd Garage", "Illini Union");
    REQUIRE(actual_line == "21raven");

    double actual_time = g.getTimeInterval("Chemical & Life Sciences", "Goodwin & Nevada");
    REQUIRE(actual_time == 0.5);
}

TEST_CASE("BFS Simple Test", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_small.csv");

    const std::vector<Vertex> expected = {"A", "B", "E"};

    std::vector<Vertex> actual = BFS(g, "A", "E");
    REQUIRE(actual == expected);

    const std::vector<Vertex> expected_2 = {"D", "C", "E"};

    actual = BFS(g, "D", "E");
    REQUIRE(actual == expected_2);
}

TEST_CASE("BFS Medium Test", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_2.csv");

    const std::vector<Vertex> expected = {"D", "A", "F", "G"};

    std::vector<Vertex> actual = BFS(g, "D", "G");
    REQUIRE(actual == expected);

    const std::vector<Vertex> expected_2 = {"E", "G"};

    actual = BFS(g, "E", "G");
    REQUIRE(actual == expected_2);

    const std::vector<Vertex> expected_3 = {"A", "F", "G", "H"};

    actual = BFS(g, "A", "H");
    REQUIRE(actual == expected_3);
}

TEST_CASE("BFS Hard Test", "[weight=5]") {
    Graph g = init("../tests/test_make_graph_3.csv");

    const std::vector<Vertex> expected = {"Goodwin & Nevada",
                                          "Goodwin & Gregory",
                                          "Gregory & Dorner",
                                          "Plant Sciences Lab",
                                          "Pennsylvania at Par"};

    std::vector<Vertex> actual = BFS(g, "Goodwin & Nevada", "Pennsylvania at Par");
    REQUIRE(actual == expected);

    const std::vector<Vertex> expected_2 = {"Penn & Dorner",
                                            "Plant Sciences Lab",
                                            "Gregory & Dorner",
                                            "Goodwin & Gregory",
                                            "Goodwin & Nevada",
                                            "Chemical & Life Sciences",
                                            "Green & Goodwin",
                                            "Illini Union",
                                            "Wright & Healey"};

    actual = BFS(g, "Penn & Dorner", "Wright & Healey");
    REQUIRE(actual == expected_2);

    const std::vector<Vertex> expected_3 = {"Illinois Terminal",
                                            "Logan & First",
                                            "White & Second",
                                            "White Street Mid-Block"};

    actual = BFS(g, "Illinois Terminal", "White Street Mid-Block");
    REQUIRE(actual == expected_3);
}

TEST_CASE("dijkstra Simple Test", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_small.csv");

    const std::vector<Vertex> expected = {"A", "B", "D"};

    std::vector<Vertex> actual = dijkstra(g, "A", "D");
    double time = time_needed(g, actual);
    REQUIRE(actual == expected);
    REQUIRE(time == 3.0);

    const std::vector<Vertex> expected_2 = {"D", "B", "A"};

    actual = dijkstra(g, "D", "A");
    time = time_needed(g, actual);
    REQUIRE(actual == expected_2);
    REQUIRE(time == 3.0);
}

TEST_CASE("dijkstra Medium Test", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_2.csv");

    const std::vector<Vertex> expected = {"A","F","E"};

    std::vector<Vertex> actual = dijkstra(g, "A", "E");
    double time = time_needed(g, actual);
    REQUIRE(actual == expected);
    REQUIRE(time == 12.0);

    const std::vector<Vertex> expected_2 = {"A","F","E","H"};

    actual = dijkstra(g, "A", "H");
    time = time_needed(g, actual);
    REQUIRE(actual == expected_2);
    REQUIRE(time == 15.0);
}

TEST_CASE("dijkstra Hard Test", "[weight=5]") {
    Graph g = init("../tests/test_make_graph_3.csv");

    const std::vector<Vertex> expected = {"Illinois Terminal",
                                          "Logan & First",
                                          "White & Second",
                                          "White Street Mid-Block"};

    std::vector<Vertex> actual = dijkstra(g, "Illinois Terminal", "White Street Mid-Block");
    double time = time_needed(g, actual);
    REQUIRE(actual == expected);
    REQUIRE(time == 3.0);

    const std::vector<Vertex> expected_2 = {"Wright & Healey",
                                            "Illini Union",
                                            "Green & Goodwin",
                                            "Chemical & Life Sciences",
                                            "Goodwin & Nevada",
                                            "Goodwin & Gregory",
                                            "Gregory & Dorner",
                                            "Plant Sciences Lab",
                                            "Penn & Dorner"};

    actual = dijkstra(g, "Wright & Healey", "Penn & Dorner");
    time = time_needed(g, actual);
    REQUIRE(actual == expected_2);
    REQUIRE(time == 7.0);
}

TEST_CASE("Betweenness Test 1", "[weight=2]") {
    Graph g = init("../data/bus_stop_info_weekday.csv");

    auto m4 = Betw(g);
    auto it = m4.find("Par");
    REQUIRE(it->second == 93);
    
    it = m4.find("Race & Holmes");
    REQUIRE(it->second == 1133);
}

TEST_CASE("Betweenness Test 2", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_small.csv");

    auto m4 = Betw(g);

    auto it = m4.find("A");
    REQUIRE(it->second == 4);

    it = m4.find("B");
    REQUIRE(it->second == 8);
}

TEST_CASE("Betweenness Test 3", "[weight=2]") {
    Graph g = init("../tests/test_make_graph_2.csv");
    auto m4 = Betw(g);

    auto it = m4.find("G");
    REQUIRE(it->second == 7);

    it = m4.find("H");
    REQUIRE(it->second == 7);

    it = m4.find("B");
    REQUIRE(it->second == 10);

    it = m4.find("E");
    REQUIRE(it->second == 12);

    it = m4.find("F");
    REQUIRE(it->second == 12);
}