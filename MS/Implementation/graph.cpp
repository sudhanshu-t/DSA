#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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

void addEdge(vve& graph, int n1, int n2, int w){
    graph[n1].push_back(Edge(n2, w));
    graph[n2].push_back(Edge(n1, w));
}

void display(vve& g){
    for(int i = 0; i < g.size(); i++){
        cout << i << " -> ";
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j].n << ", ";
        }
        cout << endl;
    }
}

vector<bool> visited (6, false);
bool hasPath(vve& g, int n1, int n2){
    if(n1 == n2){
        return true;
    }
    
    visited[n1] = true;
    for(int i = 0; i < g[n1].size(); i++){
        Edge ne = g[n1][i];

        if(visited[ne.n] == false && hasPath(g, ne.n, n2) == true){
            return true;
        }
    }

    return false;
}

void printAllPaths(vve& g, int n1, int n2, string path, vector<bool>& visited){
    if(n1 == n2){
        cout << path << endl;
        return;
    }

    visited[n1] = true;

    for(int i = 0; i < g[n1].size(); i++){
        if(!visited[g[n1][i].n]){
            printAllPaths(g, g[n1][i].n, n2, path + " " + to_string(g[n1][i].n), visited);
        }
    }

    visited[n1] = false;
}

int minWt = INT_MAX;
string minPath;
void shortestPath(vve& g, int n1, int n2, vector<bool>& visited, string path, int pathWt){
    if(n1 == n2 && pathWt < minWt){
        minWt = pathWt;
        minPath = path;
        return;
    }

    visited[n1] = true;
    for(int i = 0; i < g[n1].size(); i++){
        Edge e = g[n1][i];
        if(!visited[e.n]){
            shortestPath(g, e.n, n2, visited, path + " " + to_string(e.n), pathWt + e.w);
        }
    }
    visited[n1] = false;
}

int maxWt = INT_MIN;
string maxPath = "";

void largestPath(vve& g, int n1, int n2, vector<bool>& visited, int pathWt, string path){
    if(n1 == n2 && pathWt > maxWt){
        maxWt = pathWt;
        maxPath = path;
        return;
    }

    for(int i = 0; i < g[n1].size(); i++){
        Edge e = g[n1][i];
        if(!visited[e.n]){
            visited[e.n] = true;
            largestPath(g, e.n, n2, visited, pathWt + e.w, path + " " + to_string(e.n));
            visited[e.n] = false;
        }
    }
}

int cWt = INT_MAX;
string cPath;
void ceilPath(vve& g, int n1, int n2, int factor, vector<bool>& visited, int pathWt, string path){
    if(n1 == n2){
        if(pathWt > factor && pathWt < cWt){
            cWt = pathWt;
            cPath = path;
            return;
        }
    }

    visited[n1] = true;
    for(int i = 0; i < g[n1].size(); i++){
        Edge e = g[n1][i];
        if(!visited[e.n]){
            ceilPath(g, e.n, n2, factor, visited, pathWt + e.w, path + " " + to_string(e.n));
        }
    }
    
    visited[n1] = false;
}

int fWt = INT_MIN;
string fPath;
void floorPath(vve& g, int n1, int n2, int factor, vector<bool>& visited, int pathWt, string path){
    if(n1 == n2){
        if(pathWt < factor && pathWt > fWt){
            fWt = pathWt;
            fPath = path;
        }
        return;
    }

    visited[n1] = true;
    for(int i = 0; i < g[n1].size(); i++){
        Edge e = g[n1][i];
        if(!visited[e.n]){
            floorPath(g, e.n, n2, factor, visited, pathWt + e.w, path + " " + to_string(e.n));
        }
    }
    visited[n1] = false;
}

void kthLargest(vve& g, int n1, int n2, vector<bool>& visited, int k){
    int factor = INT_MAX;
    string kPath;
    int kPathWt;
    for(int i = 0; i < k; i++){
        floorPath(g, n1, n2, factor, visited, 0, to_string(n1));
        kPathWt = fWt;
        kPath = fPath;
        factor = fWt;
        fWt = INT_MIN;

        // cout << kPathWt << endl;
    }

    cout << k << " largest path is: " << kPath << " having weight: " << kPathWt << endl;
}

void bfs(vve& g, int n){
    vector<bool> visited (g.size());

    queue<int> q;

    q.push(n);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(!visited[front]){
            cout << front << endl;
            visited[front] = true;
        } else {
            continue;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];

            if(!visited[e.n]){
                q.push(e.n);
            }
        }
    }
}

class Pair{
public:
    int n;
    int level;

    Pair(int n, int level){
        this->n = n;
        this->level = level;
    }
};

void bfsLevelWise(vve& g, int n){
    vector<bool> visited (g.size());

    queue<Pair> q;

    q.push(Pair(n, 0));

    while(!q.empty()){
        Pair front = q.front();
        q.pop();

        if(!visited[front.n]){
            cout << front.n << " @ " << front.level <<  endl;
            visited[front.n] = true;
        } else {
            continue;
        }

        for(int i = 0; i < g[front.n].size(); i++){
            Edge e = g[front.n][i];

            if(!visited[e.n]){
                q.push(Pair(e.n, front.level + 1));
            }
        }
    }
}

class bfsHelper{
public:
    int v;
    int d;
    string p;

    bfsHelper(int v, int d, string p){
        this->v = v;
        this->d = d;
        this->p = p;
    }
};

void bfsMinEdges(vve& g, int src, int dest){
    queue<bfsHelper> q;
    vector<bool> visited (g.size());

    q.push(bfsHelper(src, 0, to_string(src)));

    while(!q.empty()){
        bfsHelper front = q.front();
        q.pop();

        if(!visited[front.v]){
            cout << "Distance from " << src << " to " << front.v << " through path " << front.p << " is " << front.d << endl;
            visited[front.v] = true;
            if(front.v == dest){
                return;
            }
        } else {
            continue;
        }

        for(int i = 0; i < g[front.v].size(); i++){
            Edge e = g[front.v][i];

            if(!visited[e.n]){
                q.push(bfsHelper(e.n, front.d + e.w, front.p + " " + to_string(e.n)));
            }
        }
    }
}

class fireHelper{
public:
    int i;
    int j;
    int t;

    fireHelper(int i, int j, int t){
        this->i = i;
        this->j = j;
        this->t = t;
    }
};

bool isValid(int i, int j, vector<vector<int>>& g){
    if(i >= g.size() || j >= g[0].size()){
        return false;
    }

    if(g[i][j] != 1){
        return false;
    }

    return true;
}

void burntAtnthSecCount(vector<vector<int>>& g, int n){
    queue<fireHelper> q;
    int ans = 0;

    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            if(g[i][j] == 2){
                cout << i << " " << j << endl;
                q.push(fireHelper(i, j, 0));
            }
        }
    }

    while(!q.empty()){
        fireHelper front = q.front();
        q.pop();


        if(front.t == 0 || g[front.i][front.j] != 2){
            g[front.i][front.j] = 2;

            cout << front.i << " " << front.j << endl;
            if(front.t == n){
                ans++;
            }
        } else {
            continue;
        }

        if(isValid(front.i, front.j - 1, g)){
            q.push(fireHelper(front.i, front.j - 1, front.t + 1));
        }

        if(isValid(front.i, front.j + 1, g)){
            q.push(fireHelper(front.i, front.j + 1, front.t + 1));
        }

        if(isValid(front.i - 1, front.j, g)){
            q.push(fireHelper(front.i - 1, front.j, front.t + 1));
        }

        if(isValid(front.i + 1, front.j, g)){
            q.push(fireHelper(front.i + 1, front.j, front.t + 1));
        }
    }

    cout << "No. of houses burnt at " << n << " second are " << ans << endl;
}

string getConnectedComponent(vve& g, int i, vector<bool>& visited){
    queue<int> q;
    string ans;
    q.push(i);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(!visited[front]){
            visited[front] = true;
            ans += to_string(front);
        } else {
            continue;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];
            if(!visited[e.n]){
                q.push(e.n);
            }
        }
    }

    return ans;
}

vector<string>* getConnectedComponents(vve& g){
    vector<bool> visited (g.size());
    vector<string>* result = new vector<string>();
    
    for(int i = 0; i < g.size(); i++){
        if(!visited[i]){
            string str = getConnectedComponent(g, i, visited);
            result->push_back(str);
        }
    }

    return result;
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

bool isValid2(int i, int j, vector<vector<int>>& g){
    if(i >= g.size() || j >= g[0].size()){
        return false;
    }

    if(g[i][j] != 0){
        return false;
    }

    return true;
}

void markElements(vector<vector<int>>& g, int i, int j){
    queue<Cell> q;

    q.push(Cell(i, j));

    while(!q.empty()){
        Cell front = q.front();
        q.pop();

        if(g[front.i][front.j] == 0){
            g[front.i][front.j] = -1;
        } else {
            continue;
        }

        if(isValid2(i+1, j, g)){
            q.push(Cell(i+1, j));
        }

        if(isValid2(i-1, j, g)){
            q.push(Cell(i-1, j));
        }

        if(isValid2(i, j+1, g)){
            q.push(Cell(i, j+1));
        }

        if(isValid2(i, j-1, g)){
            q.push(Cell(i, j-1));
        }
    }
}

int islandsCount(vector<vector<int>>& g){

    int count = 0;

    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[0].size(); j++){
            if(g[i][j] == 0){
                count++;

                markElements(g, i, j);


                for(int i = 0; i < g.size(); i++){
                    for(int j = 0; j < g[0].size(); j++){
                        cout << g[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "----------------" << endl;
            }
        }
    }

    return count;
}

bool acyclic(vve& g){
    queue<int> q;
    vector<bool> visited (g.size());
    
    q.push(0);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if(!visited[front]){
            visited[front] = true;
        } else {
            continue;
        }

        for(int i = 0; i < g[front].size(); i++){
            Edge e = g[front][i];
            if(!visited[e.n]){
                q.push(e.n);
            }
        }
    }
}

int main(){
    vector<vector<Edge>> graph (9);

    addEdge(graph, 1, 0, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 3, 2, 20);
    addEdge(graph, 3, 0, 30);
    // addEdge(graph, 4, 3, 40);
    addEdge(graph, 5, 4, 50);
    addEdge(graph, 6, 4, -20);
    addEdge(graph, 6, 5, -10);

    addEdge(graph, 7, 8, 100);


    // display(graph);

    // graph.push_back(vector<Edge>());
    // addEdge(graph, 5, 3, -10);

    display(graph);

    // cout << hasPath(graph, 4, 6) << endl;

    vector<bool> visited (graph.size());
    // printAllPaths(graph, 1, 5, "1", visited);

    // shortestPath(graph, 0, 6, visited, "0", 0);
    // cout << minPath << " " << minWt << endl;

    // visited[0] = true;
    // largestPath(graph, 0, 6, visited, 0, "0");
    // cout << maxPath << " " << maxWt << endl;

    // ceilPath(graph, 0, 5, 125, visited, 0, "0");
    // cout << cPath << " " << cWt << endl;

    // floorPath(graph, 0, 5, 125, visited, 0, "0");
    // cout << fPath << " " << fWt << endl;

    // kthLargest(graph, 0, 5, visited, 2);

    // bfs(graph, 1);
    // bfsLevelWise(graph, 1);
    // bfsMinEdges(graph, 1, 6);

    // vector<vector<int>> d = {
    //     {0,1,1,1,1,0},
    //     {0,1,0,0,1,0},
    //     {0,0,0,1,2,0},
    //     {2,1,0,1,0,1},
    //     {0,0,1,1,0,2}
    // };

    // burntAtnthSecCount(d, 5);

    // vector<string>* comps = getConnectedComponents(graph);

    // cout << comps->size() << endl;
    // for(int i = 0; i < comps->size(); i++){
    //     cout << comps->at(i) << endl;
    // }

    vector<vector<int>> islandGrid = {
        {0,0,1,1,1},
        {0,1,1,0,1},
        {1,0,1,1,1},
        {0,0,1,0,0},
        {1,0,1,1,1}
    };

    cout << islandsCount(islandGrid) << endl;

    for(int i = 0; i < islandGrid.size(); i++){
        for(int j = 0; j < islandGrid[0].size(); j++){
            cout << islandGrid[i][j] << " ";
        }
        cout << endl;
    }
}