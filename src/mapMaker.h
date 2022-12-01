#pragma once
#include <map>

#include "../lib/graph.h"
#include "../lib/edge.h"

using std::vector;
using std::map;
//using ;

class mapMaker
{
    public:
     mapMaker() = default;
     
     mapMaker(vector<vector<string>> stopinfo, map<string, vector<string>> &m);

     ~mapMaker();

    private:
     Graph* g_;

     Graph* makeGraph(vector<vector<string>> stopinfo, map<string, vector<string>> &m);

     void clear();
};
