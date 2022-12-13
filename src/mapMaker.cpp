#include "mapMaker.h"
#include "../lib/graph.h"

Graph init(std::string filename) {
    std::vector<std::vector<std::string>> v = file_to_Vec(filename);
    std::map<string, vector<string>> m;
    Graph output = makeGraph(v, m);
    return output;
}

Graph init(std::string filename, std::map<string, vector<string>> &m) {
    std::vector<std::vector<std::string>> v = file_to_Vec(filename);
    Graph output = makeGraph(v, m);
    return output;
}

std::string trim_Brackets(std::string s) {
    size_t firstP = s.find('(') - 1;
    size_t secondP = s.find(')');
    return s.erase(firstP, secondP);
}

std::vector<std::vector<std::string>> file_to_Vec(std::string filename)
{
    std::string file = file_to_string(filename);
    std::vector<string> tokens;
    std::vector<std::vector<std::string>> clean_courses;
    std::stringstream ss(file);
    std::string token;
    while (getline(ss, token, '\n')) {
        tokens.push_back(token);
    }
    for(size_t i = 0; i < tokens.size(); i++) {
        std::vector<string> t2;
        SplitString(tokens.at(i),',',t2);
        for(size_t j = 0; j < t2.size(); j++) {
            t2.at(j) = Trim(t2.at(j));
            if (t2.at(j).find('(') != std::string::npos) {
                t2.at(j) = trim_Brackets(t2.at(j));
            }
        }

        for(size_t j = 1; j < t2.size() - 2; j = j + 2) {
            std::vector<std::string> b = {t2.at(0),t2.at(j), t2.at(j+1),t2.at(j+2)};
            clean_courses.push_back(b);
        }

    }

    return clean_courses; 
}

Graph makeGraph(std::vector<std::vector<std::string>> stopinfo, std::map<string, vector<string>>& m)
{
    Graph g;
    for (auto a : stopinfo) {
        std::string busline = a[0];
        Vertex stopA = a[1];
        double time = stod(a[2]);
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
            std::vector<std::string> v {busline};
            m[stopA] = v; 
        } else {
            std::vector<std::string> v = m[stopA];
            if (find(v.begin(), v.end(), busline) == v.end()) {
                v.push_back(busline);
                m[stopA] = v;
            }
        }
    }

    return g;
}
