#include <bits/stdc++.h>
using namespace std;

// void addEdge(vector<vector<int>>& g, int i, int j){
//     g[i].push_back(j);
//     g[j].push_back(i);
// }

// vector<int> res (2);

// void cycle(vector<vector<int>>& g, int u, int v, int p, int st, vector<bool>& visited, int li, unordered_map<string, int>& map){
//     if(u == v && p == st){
//         return;
//     }

//     if(u == v && p != st){
//         string s;
//         if(st < v){
//             s = to_string(st) + "," + to_string(v);
//         } else {
//             s = to_string(v) + "," + to_string(st);
//         }
        
//         if(map[s] > li){
//             li = map[s];
//             res[0] = st;
//             res[1] = v;
//         }
        
//         return;
//     }

//     visited[u] = true;
    
//     for(int i = 0; i < g[u].size(); i++){
//         int n = g[u][i];
        
//         if(!visited[n]){
//             cycle(g, n, v, u, st, visited, li, map);
//         }
//     }
// }

// vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//     unordered_map<string, int> map;
//     unordered_set<int> set;
//     for(int i = 0; i < edges.size(); i++){
//         vector<int> pair = edges[i];
//         string s;
//         s += to_string(pair[0]) + "," + to_string(pair[1]);
//         map[s] = i;
        
//         if(set.find(pair[0]) == set.end()){
//             set.insert(pair[0]);
//         }
//         if(set.find(pair[1]) == set.end()){
//             set.insert(pair[1]);
//         }
//     }
    
//     vector<vector<int>> g (set.size()+1);
    
//     for(int i = 0; i < edges.size(); i++){
//         vector<int> edge = edges[i];
//         addEdge(g, edge[0], edge[1]);
//     }
    
//     int li = -1;
//     for(int i = 0; i < edges.size(); i++){
//         vector<bool> visited (g.size());
//         cycle(g, edges[i][0], edges[i][1], -1, edges[i][0], visited, li, map);
//     }
    
//     sort(res.begin(), res.end());
    
//     return res;
// }

int MAX_SIZE = 1000;
class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int size){
        parent.resize(size + 1);
        rank.resize(size + 1);
        
        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    bool performUnion(int x, int y){
        int xParent = find(x);
        int yParent = find(y);
        
        if(xParent == yParent){
            return false;
        } else if(rank[xParent] > rank[yParent]){
            parent[yParent] = xParent;
        } else if(rank[yParent] > rank[xParent]){
            parent[xParent] = yParent;
        } else {
            parent[yParent] = xParent;
            rank[xParent]++;
        }
        
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DSU dsu (MAX_SIZE + 1);
    for(int i = 0; i < edges.size(); i++){
        if(!dsu.performUnion(edges[i][0], edges[i][1])) return edges[i];
    }
}

int main(){
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    // vector<vector<int>> pairs = {{1,2},{1,3},{2,3}};
    vector<int> res = findRedundantConnection(pairs);
    cout << res[0] << " " << res[1] << endl;
}