#pragma once

#include <list>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>

#include "edge.h"

using std::string;
using std::vector;
using std::pair;
using std::to_string;
using std::unordered_map;


class Graph
{
    public:

     Graph();

     vector<Vertex> getAdjacent(Vertex source) const;

     vector<Vertex> getVertices() const;

     Edge getEdge(Vertex source, Vertex dest) const;

     bool vertexExists(Vertex v) const;

     bool edgeExists(Vertex source, Vertex dest) const;

     Edge setBusLine(Vertex source, Vertex dest);

     string getBusLine(Vertex source, Vertex dest) const;

     Edge setTimeInterval(Vertex source, Vertex dest);

     int getTimeInterval(Vertex source, Vertex dest) const;

     void insert(Vertex v);

     Vertex removeVertex(Vertex v);

     bool insertEdge(Vertex source, Vertex dest);

     Edge removeEdge(Vertex source, Vertex dest);

     
    private:
     mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adj_;
};
