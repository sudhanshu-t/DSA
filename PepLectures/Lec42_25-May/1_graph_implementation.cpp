#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define ve vector<Edge>
#define vve vector<ve>

using namespace std;

class Edge{
public:
    int n;
    int w;

    Edge(int n, int w){
        this->n = n;
        this->w = w;
    }
};

void add_edge(vector<vector<Edge>>& graph, int v1, int v2, int w){
    graph[v1].push_back(Edge(v2, w));
    graph[v2].push_back(Edge(v1, w));
}

void display(vector<vector<Edge>>& graph){
    for(int v = 0; v < graph.size(); v++){
        cout << v << " -> ";

        for(int e = 0; e < graph[v].size(); e++){
            Edge edge = graph[v][e];
            cout << "[" << edge.n << "-" << edge.w << "] ";
        }

        cout << endl;
    }
}

void remove_edge(vve& g, int v1, int v2){
    for(int i = 0; i < g[v1].size(); i++){
        if(g[v1][i].n == v2){
            g[v1][i].n = -1;
            g[v1][i].w = -1;
        }
    }

    for(int i = 0; i < g[v2].size(); i++){
        if(g[v2][i].n == v1){
            g[v2][i].n = -1;
            g[v2][i].w = -1;
        }
    }
}

bool has_path(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited){
    if(v1 == v2){
        return true;
    }
    
    visited[v1] = true;
    
    for(int e = 0; e < graph[v1].size(); e++){
        Edge edge = graph[v1][e];
        if(visited[edge.n] == false && has_path(graph, edge.n, v2, visited)){
            return true;
        }
    }

    return false;
}

int cpd = INT_MAX;
int fpd = INT_MIN;
void all_paths(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, string psf, int weight, int factor){
    if(v1 == v2){
        // cout << psf << v2 << endl;
        if(weight > factor && weight < cpd){
            cpd = weight;
        }
        if(weight < factor && weight > fpd){
            fpd = weight;
        }
        return;
    }

    visited[v1] = true;
    
    for(int i = 0; i < graph[v1].size(); i++){
        Edge edge = graph[v1][i];
        if(visited[edge.n] == false){
            all_paths(graph, edge.n, v2, visited, psf + to_string(v1) + " - ", weight + edge.w, factor);
        }
    }

    visited[v1] = false;
}

void all_paths_incl(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, string psf){
    if(v1 == v2){
        cout << psf << endl;
        return;
    }

    for(int i = 0; i < graph[v1].size(); i++){
        Edge edge = graph[v1][i];
        if(visited[edge.n] == false){
            visited[v1] = true;
            all_paths_incl(graph, edge.n, v2, visited, psf + " - " + to_string(edge.n));
            visited[v1] = false;
        }
    }
}

int min_val = INT_MAX;
void smallest_path(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, int weight, string psf){
    if(v1 == v2){
        cout << psf << " -> "<< weight << endl;
        if(weight < min_val){
            min_val = weight;
        }
        return;
    }
    
    for(int i = 0; i < graph[v1].size(); i++){
        Edge e = graph[v1][i];
        if(visited[e.n] == false){
            visited[e.n] = true;
            smallest_path(graph, e.n, v2, visited, weight + e.w, psf + " - " + to_string(e.n));
            visited[e.n] = false;
        }
    }
}

int max_val = INT_MIN;
void largest_path(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, int weight){
    if(v1 == v2){
        if(weight > max_val){
            // cout << weight << endl;
            max_val = weight;
        }
        return;
    }
    
    for(int i = 0; i < graph[v1].size(); i++){
        Edge e = graph[v1][i];
        if(visited[e.n] == false){
            visited[e.n] = true;
            largest_path(graph, e.n, v2, visited, weight + e.w);
            visited[e.n] = false;
        }
    }
}

int floor_val = INT_MIN;
void floor(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, int factor, int w){
    if(v1 == v2){
        if(w < factor && w > floor_val){
            floor_val = w;
        }

        return;
    }

    visited[v1] = true;
    for(int i = 0; i < graph[v1].size(); i++){
        Edge e = graph[v1][i];

        if(visited[e.n] == false){
            floor(graph, e.n, v2, visited, factor, w + e.w);
        }
    }

    visited[v1] = false;
}

int k_largest_path(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, int k){
    int factor = INT_MAX;

    for(int i = 0; i < k; i++){
        floor_val = INT_MIN;
        floor(graph, v1, v2, visited, factor, 0);
        // cout << floor_val << endl;

        factor = floor_val;
    }

    return floor_val;
}

int main(int argc, char** argv){
    vector<vector<Edge>> graph (7);

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 10);
    add_edge(graph, 0, 3, 40);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 4, 5, 3);
    add_edge(graph, 4, 6, 8);
    add_edge(graph, 5, 6, 3);

    display(graph);

    vector<bool> visited (7, false);

    // cout << has_path(graph, 0, 6, visited) << endl;

    remove_edge(graph, 3, 4);
    display(graph);

    // cout << has_path(graph, 0, 6, visited) << endl;
    // all_paths(graph, 0, 6, visited, "", 0, 45);
    // cout << cpd << endl;
    // cout << fpd << endl;

    // visited[0] = true;
    // all_paths_incl(graph, 0, 6, visited, "0");

    // visited[0] = true;
    // smallest_path(graph, 0, 6, visited, 0, "0");
    // cout << min_val << endl;

    // largest_path(graph, 0, 6, visited, 0);
    // cout << max_val << endl;

    // floor(graph, 0, 6, visited, 45, 0);
    // cout << floor_val << endl;

    // cout << k_largest_path(graph, 0, 6, visited, 2) << endl;
}