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

std::vector<Vertex> BFS(const Graph& g, Vertex s, Vertex e);

std::vector<Vertex> dijkstra(const Graph& g, Vertex s, Vertex e);