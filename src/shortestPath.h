#pragma once

#include <vector>
#include <queue>
#include <map>
#include <float.h>

#include "mapMaker.h"

using std::map;
using std::queue;
using std::priority_queue;
using std::pair;
using std::cout;
using std::endl;

/**
 * BFS traversal which will traversal the whole graph and find out the shortest path without taking account of weight in each edge
 * (The one with less vertex rather than less weight)
 * 
 * @param g The input graph which will be traversaled
 * @param s The current vertex, which is the origin
 * @param e The distination vertex, which is vertex we want to attain
 * @return A vector of vertex which represents the shortest path and includes the vertices passed by
*/
std::vector<Vertex> BFS(const Graph& g, Vertex s, Vertex e);

/**
 * Dijkstra traversal which will traversal the whole graph and find out the shortest path with taking account of weight in each edge
 * (The one with less weight in total rather than less vertex)
 * 
 * @param g The input graph which will be traversaled
 * @param s The current vertex, which is the origin
 * @param e The distination vertex, which is vertex we want to attain
 * @return A vector of vertex which represents the shortest path and includes the vertices passed by
*/
std::vector<Vertex> dijkstra(const Graph& g, Vertex s, Vertex e);

/**
 * Check how many times each vertex has been visited and rank up the visited times
 * 
 * @param g The input graph which will generate the final result
 * @return A map include the name of vertex as the key and visted times as the value
*/
std::map<Vertex,int> Betw(const Graph& g);

/**
 * Calculates the time needed of given vector of vertex
 * 
 * @param g The input graph
 * @param v Given vector of vertex
 * @return time needed from the begin of vertex to the end
*/
double time_needed(const Graph& g, const std::vector<Vertex>& v);

/**
 * Prints the shortest path and buslines
 * 
 * @param v The shortest path
 * @param m Map filled with stop name as the key and corrosponding buslines as the value
*/
void print(const std::vector<Vertex>& v, std::map<std::string, std::vector<std::string>>& m);

/**
 * Prints the top 5 stops with most visited times, that is, with hustle and bustle
 * 
 * @param g g The input graph which will generate the final result
*/
void print(const Graph& g);
