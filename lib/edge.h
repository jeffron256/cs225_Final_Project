#pragma once

#include <string>
#include <limits.h>

using std::string;

typedef string Vertex;

/**
 * Imported class and implementations from Lab_ml, altered part of its methods
 * 
 * Thanks the data structure this lab offered
 * Dec/12/2022 BY group SMARTPOINTER
*/

class Edge {
    public:
     Vertex source;
     Vertex dest;

     /**
      * Default Constructor 
      */
     Edge()
        : source(""), dest(""), busLine(""), time(-1.0)
     {
     }

     Edge(Vertex u, Vertex v)
        : source(u), dest(v), busLine(""), time(-1.0)
     {
     }

     Edge(Vertex u, Vertex v, string busLine)
        : source(u), dest(v), busLine(busLine), time(-1.0)
     {
     }

     Edge(Vertex u, Vertex v, string busLine, double time)
        : source(u), dest(v), busLine(busLine), time(time)
     {
     }

     double getTimeInterval() const 
     {
        return this->time;
     }

     string getLineName() const
     {
        return this->busLine;
     }
     
     bool operator<(const Edge& other) const
     {
        return time < other.time;
     }

    
    private:
     string busLine;
     double time;
};