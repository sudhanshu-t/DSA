#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

void addEdge(vector<vector<Edge>>& g, int s, int d, int w){
    g[s].push_back(Edge (d, w));
}

class dHelper{
public:
    int v;
    int c;

    dHelper(int v, int c){
        this->v = v;
        this->c = c;
    }

    bool operator>(const dHelper& other) const {
        return this->c > other.c;
    }
};

int networkDelayTime(vector<vector<int>>& times, int N, int K){
    priority_queue<dHelper, vector<dHelper>, greater<dHelper>> pq;

    vector<vector<Edge>> g (N+1);
    vector<int> visited (N+1, -1);

    for(int i = 0; i < times.size(); i++){
        addEdge(g, times[i][0], times[i][1], times[i][2]);
    }

    pq.push(dHelper(K, 0));

    while(!pq.empty()){
        dHelper fr = pq.top();
        pq.pop();

        if(visited[fr.v] != -1){
            continue;
        } else {
            visited[fr.v] = fr.c;
        }

        for(int i = 0; i < g[fr.v].size(); i++){
            Edge e = g[fr.v][i];
            pq.push(dHelper(e.n, fr.c + e.w));
        }
    }

    int maxTime = INT_MIN;

    for(int i = 1; i < visited.size(); i++){
        if(visited[i] == -1){
            return -1;
        }

        maxTime = max(maxTime, visited[i]);
    }

    return maxTime;
}

int main(){
    vector<vector<int>> times = {{1,2,1}, {1,3,4}, {2,3,2}};
    // vector<vector<int>> times = {{2,1,1}, {3,4,1}, {2,3,1}};
    cout << networkDelayTime(times, 3, 1) << endl;
}

// class edge{
// public:
//     int s;
//     int t;
    
//     edge(int s, int t){
//         this->s = s;
//         this->t = t;
//     }
// };

// void addEdge(vector<vector<edge>>& g, int s, int d, int w){
//     g[s].push_back(edge(d, w));
// }

// int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//     vector<vector<edge>> g (N + 1);
//     for(int i = 0; i < times.size(); i++){
//         addEdge(g, times[i][0], times[i][1], times[i][2]);
//     }

//     // for(int i = 1; i < g.size(); i++){
//     //     cout << i << " -> ";
//     //     for(int j = 0; j < g[i].size(); j++){
//     //         cout << "(" << g[i][j].s << ", " << g[i][j].t << ") ";
//     //     }
//     //     cout << endl;
//     // }
    
//     vector<int> visited (N + 1, -1);
//     queue<edge> q;
    
//     q.push(edge (K, 0));
    
//     while(q.size() != 0){
//         edge front = q.front();
//         q.pop();
        
//         if(visited[front.s] == -1){
//             visited[front.s] = front.t;
//         } else {
//             visited[front.s] = min(front.t, visited[front.s]);
//             continue;
//         }
        
//         for(int i = 0; i < g[front.s].size(); i++){
//             q.push(edge (g[front.s][i].s, front.t + g[front.s][i].t));
//         }
//     }
    
//     int maxTime = INT_MIN;
//     for(int i = 1; i < visited.size(); i++){
//         if(visited[i] == -1){
//             return -1;
//         }
        
//         maxTime = max(maxTime, visited[i]);
//     }
    
//     return maxTime;
// }
