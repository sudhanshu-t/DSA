#include <iostream>
#include <list>
#include <vector>
#include <string>

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

class THelper{
public:
    int v;
    string psf;
    int dsf;

    THelper(int v, string s, int d){
        this->v = v;
        psf = s;
        dsf = d;
    }
};

void bfs(vve& g, int src, int dest){
    list<THelper> q;
    vector<bool> visited (g.size(), false);
    q.push_back(THelper (src, to_string(src), 0));

    while(q.size() > 0){
        THelper front = q.front();
        q.pop_front();


        if(visited[front.v] == false){
            // cout << src << " to " << front.v << " via " << front.psf << " @ " << front.dsf << endl;
            visited[front.v] = true;
        } else {
            continue;
        }

        cout << front.v << " ";

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];

            if(visited[e.n] == false){
                q.push_back(THelper (e.n, front.psf + " " + to_string(e.n), front.dsf + e.w));
            }
        }
    }
}

class FHelper{
public:
    int i;
    int j;
    int t;

    FHelper(int i, int j, int t){
        this->i = i;
        this->j = j;
        this->t = t;
    }
};

bool is_valid(vector<vector<int>>& g, int i, int j){
    if(i < 0 || i >= g.size() || j < 0 || j >= g[i].size()){
        return false;
    } else if(g[i][j] >= 0 || g[i][j] == -1){
        return false;
    }

    return true;
}

// 0 is fire, -1 is water, -2 is normal
int fire_count(vector<vector<int>>& g){
    list<FHelper> q;
    int count = 0;
    
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] == 0){
                q.push_back(FHelper (i, j, 0));
            }
        }
    }

    while(q.size() > 0){
        FHelper front = q.front();
        q.pop_front();

        if(g[front.i][front.j] > 0){
            continue;
        } else {
            g[front.i][front.j] = front.t;
            count++;
        }

        if(front.t == 3){
            cout << front.i << ", " << front.j << endl;
        }

        if(is_valid(g, front.i + 1, front.j)){
            q.push_back(FHelper (front.i + 1, front.j, front.t + 1));
        }
        if(is_valid(g, front.i - 1, front.j)){
            q.push_back(FHelper (front.i - 1, front.j, front.t + 1));
        }
        if(is_valid(g, front.i, front.j + 1)){
            q.push_back(FHelper (front.i, front.j + 1, front.t + 1));
        }
        if(is_valid(g, front.i, front.j - 1)){
            q.push_back(FHelper (front.i, front.j - 1, front.t + 1));
        }
    }

    return count;
}

string get_comp(vve& g, int src, vector<bool>& visited){
    list<int> q;
    q.push_back(src);

    string comp;

    while(q.size() > 0){
        int front = q.front();
        q.pop_front();

        if(visited[front] == false){
            visited[front] = true;
            comp += to_string(front);
        } else {
            continue;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(visited[e.n] == false)
                q.push_back(e.n);
        }
    }

    return comp;
}

vector<string>* connected_comp(vve& g){
    vector<bool> visited (g.size(), false);
    vector<string>* v = new vector<string>();

    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            v->push_back(get_comp(g, i, visited));
        }
    }

    return v;
}

class Cell{
public:
    int i;
    int j;

    Cell(int i, int j){
        this->i = i;
        this->j = j;
    }
};

bool is_valid_island(vector<vector<int>>& g, int i, int j){
    if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size()){
        return false;
    } else if(g[i][j] != 0){
        return false;
    }

    return true;
}

int islands(vector<vector<int>>& g){
    int count = 0;

    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] == 0){
                count++;
                list<Cell> q;
                q.push_back(Cell (i, j));

                while (q.size() > 0)
                {
                    Cell front = q.front();
                    q.pop_front();

                    if(g[front.i][front.j] > 0){
                        continue;
                    } else {
                        g[front.i][front.j] = count;
                    }

                    if(is_valid_island(g, front.i + 1, front.j)){
                        q.push_back(Cell (front.i + 1, front.j));
                    }

                    if(is_valid_island(g, front.i - 1, front.j)){
                        q.push_back(Cell (front.i - 1, front.j));
                    }

                    if(is_valid_island(g, front.i, front.j + 1)){
                        q.push_back(Cell (front.i, front.j + 1));
                    }

                    if(is_valid_island(g, front.i, front.j - 1)){
                        q.push_back(Cell (front.i, front.j - 1));
                    }
                }   
            }
        }
    }

    return count;
}

int main(int argc, char** argv){
    vector<vector<Edge>> graph (9);

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 10);
    add_edge(graph, 0, 3, 40);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 4, 5, 3);
    add_edge(graph, 4, 6, 8);
    add_edge(graph, 5, 6, 3);
    add_edge(graph, 7, 8, 10);
    display(graph);

    // bfs(graph, 0, 6);

    // vector<vector<int>> g = {
    //     {-2,-2,0, -2,-2,-2},
    //     {-2,-1,-1,-2,-1,-1},
    //     {-2,-2,-1,-2,-2,-2},
    //     {-2,-2,-2,-2,-1,-1},
    //     {-2,-1,-1,0,-2,-2}
    // };

    // fire_count(g);

    // for(int i = 0; i < g.size(); i++){
    //     for(int j = 0; j < g[0].size(); j++){
    //         cout << g[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // vector<string>* v = connected_comp(graph);

    // for(int i = 0; i < v->size(); i++){
    //     cout << (*v)[i] << endl;
    // }

    // vector<vector<int>> g = {
    //     {0,0,-1,0,0},
    //     {0,-1,-1,-1,0},
    //     {-1,0,0,0,-1},
    //     {0,-1,0,-1,0},
    //     {0,-1,-1,-1,0}
    // };

    // cout << islands(g) << endl;

    // for(int i = 0; i < g.size(); i++){
    //     for(int j = 0; j < g[0].size(); j++){
    //         g[i][j + 1] == -1 ? cout << g[i][j] << " " : cout << g[i][j] << "  ";
    //     }

    //     cout << endl;
    // }
}