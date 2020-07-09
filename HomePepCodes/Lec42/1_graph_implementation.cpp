#include <iostream>
#include <vector>
#include <string>
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

void add_edge(vve& graph, int v1, int v2, int w){
    graph[v1].push_back(Edge(v2, w));
    graph[v2].push_back(Edge(v1, w));
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

void display(vve& graph){
    for(int i = 0; i < graph.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < graph[i].size(); j++){
            if(graph[i][j].n != -1){
                cout << "[" << graph[i][j].n << "-" << graph[i][j].w << "] ";
            }
        }

        cout << endl;
    }
}

bool has_path(vve& g, int v1, int v2, vector<bool>& visited){
    if(v1 == v2){
        return true;
    }

    for(int i = 0; i < g[v1].size(); i++){
        Edge e = g[v1][i];
        if(e.n != -1 && !visited[e.n]){
            visited[e.n] = true;
            if(has_path(g, e.n, v2, visited)){
                return true;
            }
        }
    }

    return false;
}

int min_val = INT_MAX;
int max_val = INT_MIN;

int cpd = INT_MAX;
string cp = "";

int fpd = INT_MIN;
string fp;

void all_paths(vve& g, int v1, int v2, vector<bool>& visited, string psf, int w, int factor){
    if(v1 == v2){
        psf += to_string(v2);
        cout << psf << endl;
        if(w < min_val){
            min_val = w;
        }

        if(w > max_val){
            max_val = w;
        }

        if(w > factor && w < cpd){
            cpd = w;
            cp = psf;
        }

        if(w < factor && w > fpd){
            fpd = w;
            fp = psf;
        }

        return;
    }

    visited[v1] = true;
    
    for(int i = 0; i < g[v1].size(); i++){
        Edge e = g[v1][i];

        if(!visited[e.n]){
            all_paths(g, e.n, v2, visited, psf + to_string(v1) + " - ", w + e.w, factor);
        }
    }

    visited[v1] = false;
}

int c_val = INT_MAX;
void ceil(vve& g, int v1, int v2, int factor, vector<bool>& visited, int w){
    if(v1 == v2){
        if(w > factor && w < c_val){
            c_val = w;
        }
        return;
    }

    visited[v1] = true;
    for(int i = 0; i < g[v1].size(); i++){
        Edge e = g[v1][i];

        if(visited[e.n] == false){
            ceil(g, e.n, v2, factor, visited, w + e.w);
        }
    }
    visited[v1] = false;
}

int k_smallest_path(vve& g, int v1, int v2, vector<bool> visited, int k){
    int factor = INT_MIN;

    for(int i = 0; i < k; i++){
        c_val = INT_MAX;
        ceil(g, v1, v2, factor, visited, 0);
        factor = c_val;
    }

    return factor;
}

int main(int argc, char** argv){
    vector<vector<Edge>> graph;

    for(int i = 0; i < 7; i++){
        graph.push_back(vector<Edge>());
    }

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 3, 40);
    add_edge(graph, 2, 1, 10);
    add_edge(graph, 2, 3, 10);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 5, 4, 3);
    add_edge(graph, 5, 6, 3);
    add_edge(graph, 4, 6, 8);

    display(graph);

    // remove_edge(graph, 1,2);

    // display(graph);

    vector<bool> visited (7, false);
    // visited[0] = true;

    // cout << has_path(graph, 0, 6, visited) << endl;
    // remove_edge(graph, 3, 4);
    // cout << has_path(graph, 0, 6, visited) << endl;

    // all_paths(graph, 0, 6, visited, "", 0, 45);
    // cout << min_val << endl;
    // cout << max_val << endl;
    // cout << cpd << " -> " << cp << endl;
    // cout << fpd << " -> " << fp << endl;

    // ceil(graph, 0, 6, 38, visited, 0);
    // cout << c_val << endl;

    cout << k_smallest_path(graph, 0, 6, visited, 4) << endl;
}