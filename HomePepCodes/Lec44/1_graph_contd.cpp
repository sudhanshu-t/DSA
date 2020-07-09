#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <string.h>
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

bool is_comp_cyclic(vve& g, int src, vector<bool>& visited){
    list<int> q;
    q.push_back(src);

    while(q.size() > 0){
        int front = q.front(); q.pop_front();

        if(visited[front] == true){
            return true;
        } else {
            visited[front] = true;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(visited[e.n] == false){
                q.push_back(e.n);
            }
        }
    }

    return false;
}

bool is_cyclic(vve& g){
    vector<bool> visited (g.size(), false);
    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            if(is_comp_cyclic(g, i, visited)){
                return true;
            }
        }
    }

    return false;
}

vector<vector<int>>* get_comps(vve& g){
    vector<vector<int>>* comps = new vector<vector<int>>();

    vector<bool> visited (g.size(), false);
    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            vector<int> v;

            list<int> q;
            q.push_back(i);

            while(q.size() > 0){
                int front = q.front(); q.pop_front();

                if(visited[front]){
                    continue;
                } else {
                    visited[front] = true;
                }

                v.push_back(front);

                for(int n = 0; n < g[front].size(); n++){
                    Edge e = g[front][n];

                    if(visited[e.n] == false){
                        q.push_back(e.n);
                    }
                }
            }

            comps->push_back(v);
        }
    }

    return comps;
}

int astronaut(vector<int>& a1, vector<int>& a2, int n){
    vve g (n);

    for(int i = 0; i < a1.size(); i++){
        add_edge(g, a1[i], a2[i], 0);
    }

    vector<vector<int>>* comps = get_comps(g);

    int count = 0;
    for(int i = 0; i < comps->size(); i++){
        for(int j = i + 1; j < comps->size(); j++){
            count += (*comps)[i].size() * (*comps)[j].size();
        }
    }

    for(int i = 0; i < comps->size(); i++){
        for(int j = 0; j < (*comps)[i].size(); j++){
            cout << comps->at(i)[j] << " ";
        }

        cout << endl;
    }

    return count;
}

class BP{
    public:
    int v;
    int l;

    BP(int v, int l){
        this->v = v;
        this->l = l;
    }
};

bool is_comp_bp(vve& g, int src, vector<int>& visited){
    list<BP> q;
    q.push_back(BP (src, 0));

    while(q.size() > 0){
        BP front = q.front(); q.pop_front();

        cout << front.v << " - " << front.l << endl;
        if(visited[front.v] != -1){
            if(front.l % 2 != visited[front.v] % 2){
                return false;
            }
        } else {
            visited[front.v] = front.l;
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];
            if(visited[e.n] == -1){
                q.push_back(BP (e.n, front.l + 1));
            }
        }
    }

    return true;
}

bool is_bipartite(vve& g){
    vector<int> visited (g.size(), -1);

    for(int i = 0; i < g.size(); i++){
        if(visited[i] == -1){
            if(!is_comp_bp(g, i, visited)){
                return false;
            }
        }
    }

    return true;
}

class DiaHelper{
    public:
    int v;
    int l;
    string psf;
    vector<int> path;

    DiaHelper(int v, int l, string psf, vector<int>& path){
        this->v = v;
        this->l = l;
        this->psf = psf;
        this->path = path;
    }
};

int get_dia_end(vve& g, int src){
    list<DiaHelper> q;

    vector<int> path;
    path.push_back(src);
    
    q.push_back(DiaHelper (src, 0, to_string(src), path));
    vector<bool> visited (g.size(), false);

    int max_dist = INT_MIN, farthest_v = src;

    while(q.size() > 0){
        DiaHelper front = q.front(); q.pop_front();

        if(visited[front.v] == true){
            continue;
        } else  {
            visited[front.v] = true;
        }

        // Work
        if(front.l > max_dist){
            max_dist = front.l;
            farthest_v = front.v;
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];

            if(visited[e.n] == false){
                path.push_back(e.n);
                q.push_back(DiaHelper (e.n, front.l + 1, front.psf + to_string(e.n), path));
                path.pop_back();
            }
        }
    }

    return farthest_v;
}

int min_val = INT_MAX;
int get_path(vve& g, int src, int dest){
    list<DiaHelper> q;

    vector<int> path;
    path.push_back(src);
    
    q.push_back(DiaHelper (src, 0, to_string(src), path));

    vector<bool> visited (g.size(), false);
    vector<int>* ans = new vector<int>();

    string diameter;

    while(q.size() > 0){
        DiaHelper front = q.front(); q.pop_front();

        if(visited[front.v] == true){
            continue;
        } else {
            visited[front.v] = true;
        }

        // ans->push_back(front.v);

        if(front.v == dest){
            if(front.l < min_val){
                min_val = front.l;
                diameter = front.psf;
                return front.path[front.path.size() / 2];
                // cout << front.psf << endl;

                // ans = &(front.path);
                // for(int i = 0; i < front.path.size(); i++){
                //     cout << front.path[i] << " ";
                // }

                // cout << endl;
            }
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];
            if(visited[e.n] == false){
                front.path.push_back(e.n);
                // cout << e.n << endl;
                q.push_back(DiaHelper (e.n, front.l + 1, front.psf + " " + to_string(e.n), front.path));
                front.path.pop_back();
            }
        }
    }
}

// string min_psf;
// int min_val = INT_MAX;
// string dia = "";
// void min_path(vector<vector<Edge>>& graph, int v1, int v2, vector<bool>& visited, int weight, string psf){
//     if(v1 == v2){
//         if(weight < min_val){
//             min_val = weight;
//             // cout << psf << endl;
//             dia += psf;
//             // dia = psf;
//         }
//         return;
//     }
    
//     for(int i = 0; i < graph[v1].size(); i++){
//         Edge e = graph[v1][i];
//         if(visited[e.n] == false){
//             visited[e.n] = true;
//             min_path(graph, e.n, v2, visited, weight + 1, psf + " - " + to_string(e.n));
//             visited[e.n] = false;
//         }
//     }
// }
// void get_min_path(vve& g, int v1, int v2,
//                           vector<bool>& visited, string psf, int level){
//     if(v1 == v2){
//         if(level < min_val){
//             min_val = level;
//             min_psf = psf;
//             // dia = v;

//             // for(int i = 0; i < v->size(); i++){
//             //     cout << v->at(i) << " ";
//             // }
//             // cout << endl;
//         }

//         return;
//     }

//     for(int i = 0; i < g[v1].size(); i++){
//         Edge e = g[v1][i];

//         cout << e.n << endl;
        
//         if(visited[e.n] == false){
//             visited[e.n] == true;
//             get_min_path(g, e.n, v2, visited, psf + to_string(e.n), level + 1);
//             visited[e.n] == false;
//         }
//     }
// }

int min_farthest_dist(vve& g){
    int d1 = get_dia_end(g, 0);

    cout << d1 << endl;

    int d2 = get_dia_end(g, d1);

    cout << d2 << endl;

    // vector<int>* ans = 
    cout << "Vertex is " << get_path(g, d1, d2) << endl;

    // cout << ans->size() << endl;

    // cout << (*ans)[0] << " ";
    // cout << (*ans)[1] << " ";
    // cout << (*ans)[2] << " ";
    // cout << (*ans)[3] << " ";
    // cout << (*ans)[4] << " ";
    // cout << (*ans)[5] << " ";
    // cout << (*ans)[6] << " ";
    // cout << (*ans)[7] << " ";
    // cout << (*ans)[8] << " ";
    // cout << (*ans)[9] << " ";
    // string diameter = get_path(g, d1, d2);
    // cout << diameter << endl;

    // cout << ans->size() << endl;
    // cout << ans->at(0) << endl;

    // cout << ans->size() << endl;

    // for(int i = 0; i < ans->size(); i++){
    //     cout << ans->at(i) << " ";
    // }

    // cout << endl;

    // vector<bool> visited (g.size(), false);
    // vector<int>* v = new vector<int>();
    // vector<int>* dia = new vector<int>();

    // visited[d1] = true;
    // v->push_back(d1);
    // min_path(g, d1, d2, visited, 0, to_string(d1));


    // cout << dia << endl;
    // cout << dia.size() << endl;

    // for(int i = 0; i < dia->size(); i++){
    //     cout << dia->at(i) << " ";
    // }

    cout << endl << min_val << endl;
}

void is_comp_connected(vve& g, int src, vector<bool>& visited){
    list<int> q;
    q.push_back(src);

    while(q.size() > 0){
        int front = q.front(); q.pop_front();

        if(visited[front] == true){
            continue;
        } else {
            visited[front] = true;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(visited[e.n] == false){
                q.push_back(e.n);
            }
        }
    }
}

bool is_connected(vve& g){
    vector<bool> visited (g.size(), false);
    int count = 0;
    
    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            count++;
            is_comp_connected(g, i, visited);
        }
    }

    // cout << count << endl;
    if(count != 1)
       return false;
    
    return true;
}

bool is_tree(vve& g){
    if(is_connected(g)){
        if(is_cyclic(g)){
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void print_hamiltonian_paths(vve& g, int src, vector<bool>& visited, int count, string psf, int os){
    if(count == g.size()){
        for(int i = 0; i < g[src].size(); i++){
            Edge e = g[src][i];

            if(e.n == os){
                cout << psf << "*" << endl;
                return;
            }
        }
        
        cout << psf << "." << endl;
        return;
    }

    visited[src] = true;

    for(int i = 0; i < g[src].size(); i++){
        Edge e = g[src][i];
        if(visited[e.n] == false){
            print_hamiltonian_paths(g, e.n, visited, count + 1, psf + to_string(e.n), os);
        }
    }

    visited[src] = false;
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
    add_edge(graph, 5, 2, 10);
    // add_edge(graph, 7, 8, 10);
    // display(graph);

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

    // cout << is_cyclic(graph) << endl;

    // vector<int> astro1 = {1,6,3,2,9,10,0};
    // vector<int> astro2 = {2,9,8,5,5,3,11};
    // cout << astronaut(astro1, astro2, 12) << endl;

    // vve g1 (5);
    // add_edge(g1, 0, 1, 0);
    // add_edge(g1, 0, 3, 0);
    // add_edge(g1, 2, 1, 0);
    // add_edge(g1, 2, 4, 0);
    // add_edge(g1, 2, 3, 0);
    // add_edge(g1, 3, 4, 0);

    // display(g1);

    // vve g (6);
    // add_edge(g, 0, 1, 0);
    // add_edge(g, 0, 3, 0);
    // add_edge(g, 2, 1, 0);
    // add_edge(g, 2, 5, 0);
    // add_edge(g, 2, 3, 0);
    // add_edge(g, 4, 3, 0);
    // add_edge(g, 4, 5, 0);

    // cout << is_bipartite(graph) << endl;

    vve g (23);

    add_edge(g, 0, 1, 0);
    add_edge(g, 2, 1, 0);
    add_edge(g, 3, 1, 0);
    add_edge(g, 3, 4, 0);
    add_edge(g, 3, 5, 0);
    add_edge(g, 5, 7, 0);
    add_edge(g, 5, 6, 0);
    add_edge(g, 3, 8, 0);
    add_edge(g, 8, 9, 0);
    add_edge(g, 10, 9, 0);
    add_edge(g, 10, 11, 0);
    add_edge(g, 10, 12, 0);
    add_edge(g, 10, 13, 0);
    add_edge(g, 13, 14, 0);
    add_edge(g, 14, 15, 0);
    add_edge(g, 14, 16, 0);
    add_edge(g, 8, 17, 0);
    add_edge(g, 18, 17, 0);
    add_edge(g, 19, 18, 0);
    add_edge(g, 18, 20, 0);
    add_edge(g, 20, 21, 0);
    add_edge(g, 20, 22, 0);

    min_farthest_dist(g);

    // cout << is_connected(graph) << endl;

    // cout << is_tree(g) << endl;

    // vector<bool> visited (graph.size(), false);
    // print_hamiltonian_paths(graph, 0, visited, 1, "0", 0);
}