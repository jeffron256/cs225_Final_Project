#include "shortestPath.h"

double time_needed(const Graph& g, const std::vector<Vertex>& v) {
    double time = 0;
    for (size_t i = 1; i < v.size(); i++) {
        Vertex tmp = v[i - 1];
        time += g.getTimeInterval(tmp, v[i]);
    }
    return time;
}

std::vector<Vertex> BFS(const Graph& g, Vertex s, Vertex e) {
    std::vector<Vertex> output;
    std::queue<Vertex> q;
    std::map<Vertex, Vertex> pre;
    std::map<Vertex, bool> visited;

    for (auto v : g.getVertices()) {
        pre[v] = "";
        visited[v] = false;
    }
    q.push(s);

    while (!q.empty()) {
        Vertex curr = q.front();
        q.pop();

        visited[curr] = true;

        for (auto v : g.getAdjacent(curr)) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                pre[v] = curr;
            }
        }
    }

    Vertex v = e;
    while (v != "") {
        output.push_back(v);
        v = pre[v];
    }
    std::reverse(output.begin(), output.end());

    return output;
}

std::vector<Vertex> dijkstra(const Graph& g, Vertex s, Vertex e) { 
    map<Vertex, float> t; //time taken from s to v
    map<Vertex, Vertex> p; //predecessor of v
    map<Vertex, bool> visited; 

    priority_queue<pair<float, string>, vector<pair<float,string>>, std::greater<pair<float,string>>> q; //min time
    
    for (Vertex v : g.getVertices()) {
        t[v] = DBL_MAX;
        p[v] = "";
        visited[v] = false;
    }
    t[s] = 0;
    q.push(pair<float, Vertex> {t[s], s});

    while (!q.empty()) {
        
        Vertex u = q.top().second;
        if (q.top().first != t[u]) {
            q.pop();
            q.push(pair<float, Vertex> {t[u], u});
            continue;
        }

        q.pop();

        visited[u] = true;

        for (Vertex v : g.getAdjacent(u)) {

            if (!visited[v] && (g.getTimeInterval(u,v) + t[u]) < t[v]) {
                t[v] = g.getTimeInterval(u,v) + t[u];
                q.push(pair<float, Vertex> {t[v], v});  //update time for v
                p[v] = u;

            }
        }

    }

    vector<Vertex> output;
    Vertex v = e;
    while (v != "") {
        output.push_back(v);
        v = p[v];
    }
    std::reverse(output.begin(), output.end());
   
    return output;
}

std::map<Vertex,int> Betw(const Graph& g) {
    //get list of the stations 
    std::vector<Vertex> stations = g.getVertices();
    map<Vertex,int>certa;
    //put them into the map to record the time expereicned
    for(size_t i = 0; i < stations.size();i++) {
        certa.insert(std::pair<Vertex,int>(stations.at(i),0));
    }
    //add all thepathss into the map
    for(size_t i = 0; i< stations.size();i++) {
        for(size_t j =i+1; j< stations.size();j++) {
            std::vector<Vertex> rout = dijkstra(g,stations.at(i),stations.at(j));
            for(size_t z = 0; z < rout.size(); z++) {
                auto it = certa.find(rout.at(z)); 
                if (it != certa.end())
                it->second = it->second + 1;
            }

        }
    }
    return certa;
}

void print(const std::vector<Vertex>& v, std::map<string, vector<string>>& m) {
    cout << "    ";
    for (auto i : v) {
        if (i == v.back()) {
            cout << i;
            cout << i << " (";
            for (auto l: m[i]) {
                if (l == m[i].back()) {
                    cout << l;
                } else {
                    cout << l << "/";
                }
            }
            cout << ")"<< endl;
        } else {
            cout << i << " (";
            for (auto l: m[i]) {
                if (l == m[i].back()) {
                    cout << l;
                } else {
                    cout << l << "/";
                }
            }
            cout << ")" << endl;
            cout << " -> ";
        }
    }
}

void print(const Graph& g, const std::vector<std::string>& v) {
    auto m4 = Betw(g);
    vector<pair<string, int>> A;

    for (auto it : v) {
        if (m4.find(it) != m4.end()) {
            A.push_back(std::make_pair(it, m4[it]));
        }
    }

    sort(A.begin(), A.end(), cmp);

    cout << A[0].first << " " << A[0].second << endl;
}