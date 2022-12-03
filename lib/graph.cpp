#include "graph.h"

const Vertex Graph::InvalidVertex = "INVALIDVERTEX";
const double Graph::InvalidWeight = INT_MIN;
const string Graph:: InvalidLabel = "INVALIDLABEL";
const Edge Graph::InvalidEdge = Edge(Graph::InvalidVertex, Graph::InvalidVertex, Graph::InvalidLabel, Graph::InvalidWeight);

vector<Vertex> Graph::getAdjacent(Vertex source) const
{
    auto lookup = adj_.find(source);

    if(lookup == adj_.end())
        return vector<Vertex>();

    else
    {
        vector<Vertex> vertex_list;
        unordered_map <Vertex, Edge> & map = adj_[source];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }
}

vector<Vertex> Graph::getVertices() const
{
    vector<Vertex> ret;

    for(auto it = adj_.begin(); it != adj_.end(); it++)
    {
        ret.push_back(it->first);
    }

    return ret;
}

Edge Graph::getEdge(Vertex source, Vertex dest) const
{
    if(assertEdgeExists(source, dest, __func__) == false)
        return Edge();
    Edge ret = adj_[source][dest];
    return ret;
}

bool Graph::vertexExists(Vertex v) const
{
    return assertVertexExists(v, "");
}

bool Graph::edgeExists(Vertex source, Vertex dest) const
{
    return assertEdgeExists(source, dest, "");
}

Edge Graph::setBusLine(Vertex source, Vertex dest, string busLine)
{
    if (assertEdgeExists(source, dest, __func__) == false)
        return InvalidEdge;
    Edge e = adj_[source][dest];
    Edge new_edge(source, dest, busLine, e.getTimeInterval());
    adj_[source][dest] = new_edge;

    Edge new_edge_reverse(dest,source, busLine, e.getTimeInterval());
    adj_[dest][source] = new_edge_reverse;

    return new_edge;
}

string Graph::getBusLine(Vertex source, Vertex dest) const
{
    if(assertEdgeExists(source, dest, __func__) == false)
        return InvalidLabel;
    return adj_[source][dest].getLineName();
}

Edge Graph::setTimeInterval(Vertex source, Vertex dest, double time)
{
    if (assertEdgeExists(source, dest, __func__) == false)
        return InvalidEdge;
    Edge e = adj_[source][dest];
    Edge new_edge(source, dest, e.getLineName(), time);
    adj_[source][dest] = new_edge;

    Edge new_edge_reverse(dest,source, e.getLineName(), time);
    adj_[dest][source] = new_edge_reverse;
    return new_edge;
}

double Graph::getTimeInterval(Vertex source, Vertex dest) const
{
    if(assertEdgeExists(source, dest, __func__) == false)
        return InvalidWeight;
    return adj_[source][dest].getTimeInterval();
}

void Graph::insertVertex(Vertex v)
{
    removeVertex(v);
    adj_[v] = unordered_map<Vertex, Edge>();   
}

Vertex Graph::removeVertex(Vertex v)
{
    if (adj_.find(v) != adj_.end())
    {
        for (auto it = adj_[v].begin(); it != adj_[v].end(); it++)
        {
            Vertex u = it->first;
            adj_[u].erase(v); 
        }

        adj_.erase(v);
        return v;
        
        adj_.erase(v);
        for(auto it2 = adj_.begin(); it2 != adj_.end(); it2++)
        {
            Vertex u = it2->first;
            if (it2->second.find(v)!=it2->second.end())
            {
                it2->second.erase(v);
            }
        }
        return v;
    }

    return InvalidVertex;
}

bool Graph::insertEdge(Vertex source, Vertex dest)
{
    if(adj_.find(source)!= adj_.end() 
    && adj_[source].find(dest)!= adj_[source].end())
    {
        //edge already exit
        return false;
    }

    if(adj_.find(source)==adj_.end())
    {
        adj_[source] = unordered_map<Vertex, Edge>();
    }

        //source vertex exists
    adj_[source][dest] = Edge(source, dest);
    if(adj_.find(dest)== adj_.end())
    {
        adj_[dest] = unordered_map<Vertex, Edge>();
    }
    adj_[dest][source] = Edge(source, dest);

    return true;
}

Edge Graph::removeEdge(Vertex source, Vertex dest)
{
    if(assertEdgeExists(source, dest, __func__) == false)
        return InvalidEdge;
    Edge e = adj_[source][dest];
    adj_[source].erase(dest);
    adj_[dest].erase(source);
    return e;
}

bool Graph::assertVertexExists(Vertex v, string functionName) const
{
    if (adj_.find(v) == adj_.end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent vertices");
        return false;
    }
    return true;
}

bool Graph::assertEdgeExists(Vertex source, Vertex dest, string functionName) const
{
    if(assertVertexExists(source,functionName) == false)
        return false;
    if(adj_[source].find(dest)== adj_[source].end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent edge " + source + " -> " + dest);
        return false;
    }

    if (assertVertexExists(dest,functionName) == false)
        return false;
    if(adj_[dest].find(source)== adj_[dest].end())
    {
        if (functionName != "")
            error(functionName + " called on nonexistent edge " + dest + " -> " + source);
        return false;
    }

    return true;
}

void Graph::error(string message) const
{
    std::cerr << "\033[1;31m[Graph Error]\033[0m " + message << std::endl;
}


