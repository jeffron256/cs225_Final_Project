#include "mapMaker.h"

mapMaker::mapMaker(vector<vector<string>> stopinfo, map<string, vector<string>> &m)
{
    g_ = makeGraph(stopinfo, m);
}

mapMaker::~mapMaker()
{
    clear();
}

void mapMaker::clear()
{
    delete g_;
    g_ = NULL;
}

Graph* mapMaker::makeGraph(vector<vector<string>> stopinfo, map<string, vector<string>> &m)
{
    Graph* g = new Graph();
    for (auto a : stopinfo) {
        string busline = a[0];
        Vertex stopA = a[1];
        int time = stoi(a[2]);
        Vertex stopB = a[3];
        if (!g->vertexExists(stopA)) {
            g->insertVertex(stopA);
        }
        if (!g->vertexExists(stopB)) {
            g->insertVertex(stopB);
        }
        if (!g->edgeExists(stopA, stopB)) {
            g->insertEdge(stopA, stopB);
            g->setTimeInterval(stopA, stopB, time);
        }
        //store multiple busline in a vertex
        // m : map each bus stop to a vector containing all buslines pass through it
        if (m.find(stopA) == m.end()) {
            vector<string> v {busline};
            m[stopA] = v; 
        } else {
            vector<string> v = m[stopA];
            if (std::find(v.begin(), v.end(), busline) == v.end()) {
                v.push_back(busline);
                m[stopA] = v;
            }
        }
    }

    return g;
}