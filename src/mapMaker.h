#pragma once
#include <map>
#include <sstream>

#include "../lib/graph.h"
#include "../lib/edge.h"
#include "utils.h"

using std::vector;
using std::map;
using std::stringstream;

class mapMaker
{
    public:
     mapMaker() = default;
     
     mapMaker(vector<vector<string>> stopinfo, map<string, vector<string>> &m);

     vector<vector<string>> file_to_Vec(string filename);

     Graph makeGraph(vector<vector<string>> stopinfo, map<string, vector<string>> &m);
};
