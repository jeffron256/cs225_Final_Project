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

     Graph() = default;

     vector<Vertex> getAdjacent(Vertex source) const;

     vector<Vertex> getVertices() const;

     Edge getEdge(Vertex source, Vertex dest) const;

     bool vertexExists(Vertex v) const;

     bool edgeExists(Vertex source, Vertex dest) const;

     Edge setBusLine(Vertex source, Vertex dest, string busLine);

     string getBusLine(Vertex source, Vertex dest) const;

     Edge setTimeInterval(Vertex source, Vertex dest, double time);

     double getTimeInterval(Vertex source, Vertex dest) const;

     void insertVertex(Vertex v);

     Vertex removeVertex(Vertex v);

     bool insertEdge(Vertex source, Vertex dest);

     Edge removeEdge(Vertex source, Vertex dest);

     const static Vertex InvalidVertex;
     const static Edge InvalidEdge;
     const static double InvalidWeight;
     const static string InvalidLabel;


    private:

     mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adj_;

     bool assertVertexExists(Vertex v, string functionName) const;

     bool assertEdgeExists(Vertex source, Vertex dest, string functionName) const;

     void error(string message) const;
};
