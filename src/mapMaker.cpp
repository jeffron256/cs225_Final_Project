#include "mapMaker.h"
#include "../lib/graph.h"

std::string trim2(std::string InitialStationname) {
    size_t firstP= InitialStationname.find('(') - 1;
    size_t secondP= InitialStationname.find(')');
    return InitialStationname.erase(firstP,secondP);
}

vector<vector<string>> file_to_Vec(string filename)
{
    string file = file_to_string(filename);
    vector<string> tokens;
    vector<vector<string>> clean_courses;
    stringstream ss(file);
    string token;
    while (getline(ss, token, '\n')) {
        tokens.push_back(token);
    }
    for(size_t i =0; i<tokens.size();i++) {

        vector<string> t2;
        SplitString(tokens.at(i),',',t2);
        for( size_t j = 0; j < t2.size();j++) {
            t2.at(j) = Trim(t2.at(j));
            if (t2.at(j).find('(') != std::string::npos) {
                t2.at(j)=trim2(t2.at(j));
            }
        }

        for(size_t j = 1; j < t2.size()-2;j=j+2) {
            vector<string> b = {t2.at(0),t2.at(j), t2.at(j+1),t2.at(j+2)};
            clean_courses.push_back(b);
        }

    }

    return clean_courses; 
}

Graph makeGraph(vector<vector<string>> stopinfo, map<string, vector<string>> &m)
{
    Graph g;
    for (auto a : stopinfo) {
        string busline = a[0];
        Vertex stopA = a[1];
        double time = stoi(a[2]);
        Vertex stopB = a[3];
        if (!g.vertexExists(stopA)) {
            g.insertVertex(stopA);
        }
        if (!g.vertexExists(stopB)) {
            g.insertVertex(stopB);
        }
        if (!g.edgeExists(stopA, stopB)) {
            g.insertEdge(stopA, stopB);
            g.setTimeInterval(stopA, stopB, time);
            g.setBusLine(stopA, stopB, busline);
        }
        //store multiple busline in a vertex
        // m : map each bus stop to a vector containing all buslines pass through it
        if (m.find(stopA) == m.end()) {
            vector<string> v {busline};
            m[stopA] = v; 
        } else {
            vector<string> v = m[stopA];
            if (find(v.begin(), v.end(), busline) == v.end()) {
                v.push_back(busline);
                m[stopA] = v;
            }
        }
    }

    return g;
}
