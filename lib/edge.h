#pragma once

#include <string>
#include <limits.h>

using std::string;

typedef string Vertex;

class Edge {
    public:
     Vertex source;
     Vertex dest;

     /**
      * Default Constructor 
      */
     Edge()
        : source(""), dest(""), busLine(""), time(-1)
     {
     }

     Edge(Vertex u, Vertex v)
        : source(u), dest(v), busLine(""), time(-1)
     {
     }

     Edge(Vertex u, Vertex v, string busLine)
        : source(u), dest(v), busLine(busLine), time(-1)
     {
     }

     Edge(Vertex u, Vertex v, string busLine, int time)
        : source(u), dest(v), busLine(busLine), time(time)
     {
     }

     int getTimeInterval() const 
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
     int time;
};