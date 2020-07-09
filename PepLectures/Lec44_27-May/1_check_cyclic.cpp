#include <iostream>
#include <string>
#include <vector>
#include <list>
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

// ============ TRAVERSALS ============= //

class THelper{
    public:
    int v;
    string psf;
    int dsf;

    THelper(int v, string psf, int dsf){
        this->v = v;
        this->psf = psf;
        this->dsf = dsf;
    }
};

bool bfs(vve& g, int src, int dest){
    vector<bool> visited (g.size(), false);
    list<THelper> queue;

    queue.push_back(THelper (src, to_string(src), 0));

    while(queue.size() > 0){
        THelper front = queue.front();
        queue.pop_front();

        cout << src << " to " << front.v << " via " << front.psf << " @ " << front.dsf << endl;

        if(visited[front.v] == true){
            continue;
        } else {
            visited[front.v] = true;
            // cout << front.v << " ";
        }

        if(front.v == dest){
            return true;
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];

            if(visited[e.n] == false){
                queue.push_back(THelper (e.n, front.psf + to_string(e.n), front.dsf + e.w));
            }
        }
    }
}

int count = 2;
void fire_count(vector<vector<int>>& d, int i, int j, int t){
    if(t == 0){
        d[i][j] = 2;
        return;
    }
    
    d[i][j] = 2;

    if(j+1 < d[0].size() && d[i][j+1] == 0){
        count++;
        fire_count(d, i, j+1, t-1);
    }

    if(j-1 >= 0 && d[i][j-1] == 0){
        count++;
        fire_count(d, i, j-1, t-1);
    }

    if(i+1 < d.size() && d[i+1][j] == 0){
        count++;
        fire_count(d, i+1, j, t-1);
    }

    if(i-1 >= 0 && d[i-1][j] == 0){
        count++;
        fire_count(d, i-1, j, t-1);
    }
}

class FHelper{
public:
    int i;
    int j;
    int t;

    FHelper(int i, int j, int t)
    {
        this->i = i;
        this->j = j;
        this->t = t;
    }
};

bool is_valid(vector<vector<int>>& matrix, int i, int j){
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()){
        return false;
    } else if(matrix[i][j] == -1){
        return false;
    } else if(matrix[i][j] >= 0){
        return false;
    }

    return true;
}

// -2 is normal, -1 is water, 0 is fire
void fire_storm(vector<vector<int>>& matrix){
    list<FHelper> queue;

    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                queue.push_back(FHelper (i, j, 0));
            }
        }
    }

    while(queue.size() > 0 && queue.front().t <= 3){
        FHelper front = queue.front();
        queue.pop_front();

        if(matrix[front.i][front.j] > 0){
            // Already burnt
            continue;
        } else {
            matrix[front.i][front.j] = front.t;
        }

        cout << front.i << " - " << front.j << " burnt at " << front.t << endl;
        if(is_valid(matrix, front.i - 1, front.j))
            queue.push_back(FHelper (front.i - 1, front.j, front.t + 1));

        if(is_valid(matrix, front.i + 1, front.j))
            queue.push_back(FHelper (front.i + 1, front.j, front.t + 1));

        if(is_valid(matrix, front.i, front.j + 1))
            queue.push_back(FHelper (front.i, front.j + 1, front.t + 1));
            
        if(is_valid(matrix, front.i, front.j - 1))
            queue.push_back(FHelper (front.i, front.j - 1, front.t + 1));
    }
}

vector<string>* connected_components(vve& g){
    vector<bool> visited (g.size(), false);
    vector<string>* v = new vector<string>();
    
    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            string ans;
            list<int> queue;

            queue.push_back(i);

            while(queue.size() > 0){
                int front = queue.front();
                queue.pop_front();

                if(visited[front] == true){
                    continue;
                } else {
                    visited[front] = true;
                }

                ans += to_string(front);

                for(int j = 0; j < g[front].size(); j++){
                    Edge e = g[front][j];
                    
                    if(visited[e.n] == false){
                        queue.push_back(e.n);
                    }
                }
            }

            cout << ans << endl;

            (*v).push_back(ans);
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
    } else if(g[i][j] == -1 || g[i][j] == 1){
        return false;
    }

    return true;
}

void get_component(vector<vector<int>>& g, int i, int j){
    Cell c(i, j);

    list<Cell> q;
    q.push_back(c);

    while(q.size() > 0){
        Cell front = q.front();
        q.pop_front();

        if(g[front.i][front.j] == 0){
            g[front.i][front.j] = 1;
        } else {
            continue;
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

int islands(vector<vector<int>>& g){
    int num = 0;

    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] != -1){
                if(g[i][j] == 0){
                    num++;
                    get_component(g, i, j);
                }
            }
        }
    }

    return num;
}

bool is_component_cyclic(vve& g, int src, vector<bool>& visited){
    list<int> q;

    q.push_back(src);

    while(q.size() > 0){
        int front = q.front();
        q.pop_front();

        if(visited[front] == true){
            return true;
        } else {
            visited[front] = true;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(visited[e.n] == false)
                q.push_back(e.n);
        }
    }

    return false;
}

bool is_cyclic(vve& g){
    vector<bool> visited (g.size(), false);

    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            if(is_component_cyclic(g, i, visited)){
                return true;
            }
        }
    }

    return false;
}

int get_comp_size(vve& g, int src, vector<bool>& visited){
    list<int> q;
    int num = 0;
    q.push_back(src);

    while(q.size() > 0){
        int front = q.front();
        q.pop_front();

        if(visited[front] == true){
            continue;
        }
        else {
            visited[front] = true;
            num++;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(visited[e.n] == false){
                q.push_back(e.n);
            }
        }
    }

    return num;
}

int astronaut(vector<int>& astro1, vector<int>& astro2, int n){
    vve g (n);
    
    for(int i = 0; i < astro1.size(); i++){
        int one = astro1[i];
        int two = astro2[i];

        add_edge(g, one, two, 0);
    }

    display(g);

    vector<int> sizes;
    vector<bool> visited (n, false);

    for(int i = 0; i < g.size(); i++){
        if(visited[i] == false){
            int size = get_comp_size(g, i, visited);
            sizes.push_back(size);
        }
    }

    // cout << sizes.size() << endl << endl;

    int sum = 0;
    for(int i = 0; i < sizes.size() - 1; i++){
        for(int j = i + 1; j < sizes.size(); j++){
            sum += sizes[i] * sizes[j];
        }
    }

    for(int i = 0; i < sizes.size(); i++){
        cout << sizes[i] << endl;
    }

    return sum;
}

class BP{
    public:
    int v;
    int level;

    BP(int v, int l){
        this->v = v;
        this->level = l;
    }
};

bool bipartite(vve& g, int src, vector<int>& visited){
    list<BP> q;
    q.push_back(BP (src,0));

    while(q.size() > 0){
        BP front = q.front();
        q.pop_front();

        cout << front.v << " - " << front.level << endl;

        if(visited[front.v] == -1){
            visited[front.v] = front.level;
        } else {
            if(front.level%2 != visited[front.v]%2){
                return false;
            }
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];

            if(visited[e.n] == -1)
                q.push_back(BP (e.n, front.level + 1));
        }
    }

    return true;
}

bool is_bipartite(vve& g){
    vector<int> visited (g.size(), -1);

    for(int i = 0; i < g.size(); i++){
        if(visited[i] == -1){
            if(!bipartite(g, i, visited)){
                return false;
            }
        }
    }

    return true;
}

// int min_farthest_distance_vertex_On2(vve& g){
//     int min_val = INT_MAX;
//     for(int i = 0; i < g.size(); i++){
//         vector<bool> visited (g.size(), false);        
//     }
// }

int main(){
    vector<vector<Edge>> graph (9);

    add_edge(graph, 0, 1, 10);
    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 10);
    add_edge(graph, 0, 3, 40);
    add_edge(graph, 3, 4, 2);
    add_edge(graph, 4, 5, 3);
    add_edge(graph, 4, 6, 8);
    // add_edge(graph, 5, 6, 3);

    // display(graph);

    // bfs(graph, 0, 6);

    // vector<vector<int>> d = {
    //     {0,1,1,1,1,0},
    //     {0,1,0,0,1,0},
    //     {0,0,0,1,0,0},
    //     {0,1,0,1,0,1},
    //     {0,0,1,1,0,0}
    // };

    // fire_count(d, 2, 5, 3);
    // fire_count(d, 4, 0, 3);
    // cout << count << endl;

    // for(int i = 0; i < d.size(); i++){
    //     for(int j = 0; j < d[0].size(); j++){
    //         cout << d[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // cout << endl;

    // vector<vector<int>> d = {
    //     {0,1,1,1,1,0},
    //     {0,1,0,0,1,0},
    //     {0,0,0,1,0,0},
    //     {0,1,0,1,0,1},
    //     {0,0,1,1,0,0}
    // };

    // fire_count(d, 2, 5, 3);
    // fire_count(d, 4, 0, 3);
    // cout << count << endl;
        
    // vector<vector<int>> d = {
    //     {-2,-2,0, -2,-2,-2},
    //     {-2,-1,-1,-2,-1,-1},
    //     {-2,-2,-1,-2,-2,-2},
    //     {-2,-2,-2,-2,-1,-1},
    //     {-2,-1,-1,0,-2,-2}
    // };

    // fire_storm(d);
    // for(int i = 0; i < d.size(); i++){
    //     for(int j = 0; j < d[0].size(); j++){
    //         cout << d[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // add_edge(graph, 7, 8, 10);

    // remove_edge(graph, 3, 4);

    // display(graph);

    // vector<string>* v = connected_components(graph);

    // cout << v->size() << endl;
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
    //         cout << g[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // display(graph);
    // cout << is_cyclic(graph) << endl;


    // vector<int> astro1 = {1,6,3,2,9,10,0};
    // vector<int> astro2 = {2,9,8,5,5,3,11};
    // cout << astronaut(astro1, astro2, 12) << endl;

    // vve g (5);
    // add_edge(g, 0, 1, 0);
    // add_edge(g, 0, 3, 0);
    // add_edge(g, 2, 1, 0);
    // add_edge(g, 2, 4, 0);
    // add_edge(g, 3, 4, 0);

    // display(g);

    // vve g (6);
    // add_edge(g, 0, 1, 0);
    // add_edge(g, 0, 3, 0);
    // add_edge(g, 2, 1, 0);
    // add_edge(g, 2, 5, 0);
    // add_edge(g, 2, 3, 0);
    // add_edge(g, 4, 3, 0);
    // add_edge(g, 4, 5, 0);

    cout << is_bipartite(graph) << endl;
}