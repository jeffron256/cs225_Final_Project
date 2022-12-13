#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <set>
#include <sstream>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;
using std::pair;
using std::to_string;
using std::unordered_map;
using std::cout;
using std::endl;

/**
 * Imported class and implementations from Lab_ml, altered part of its methods
 * 
 * Thanks the data structure this lab offered
 * Dec/12/2022 BY group SMARTPOINTER
*/

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

     void print() const;

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
