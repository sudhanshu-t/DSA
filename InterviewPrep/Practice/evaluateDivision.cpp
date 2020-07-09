#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <iomanip>

using namespace std;

class edge{
public:
    string v;
    double c;

    edge(string v, double c){
        this->v = v;
        this->c = c;
    }
};

void addEdge(vector<vector<edge>>& g, unordered_map<string, int>& map, string v1, string v2, double value){
    g[map[v1]].push_back(edge (v2, value));
    double invValue = 1 / value;
    g[map[v2]].push_back(edge (v1, invValue));
}

bool found;

double findValue(vector<vector<edge>>& g, unordered_map<string, int>& map, vector<bool>& visited, string v1, string v2, double vsf){
    // cout << v1 << " to " << v2 << " is cost: " << vsf << endl;
    
    if(v1 == v2){
        found = true;
        return vsf;
    }

    visited[map[v1]] = true;
    
    double value;

    for(int i = 0; i < g[map[v1]].size(); i++){
        edge e = g[map[v1]][i];

        if(!visited[map[e.v]]){
            value = findValue(g, map, visited, e.v, v2, vsf * e.c);

            if(found)
                return value;
        }
    }
    
    return value;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> map;
    int index = 0;

    for(int i = 0; i < equations.size(); i++){
        string v1 = equations[i][0];
        string v2 = equations[i][1];

        if(map.find(v1) == map.end()){map[v1] = index++;}
        if(map.find(v2) == map.end()){map[v2] = index++;}
    }

    int size = map.size();
    vector<vector<edge>> graph (size);

    for(int i = 0; i < equations.size(); i++){
        string v1 = equations[i][0];
        string v2 = equations[i][1];

        addEdge(graph, map, v1, v2, values[i]);
    }

    // for(int i = 0; i < graph.size(); i++){
    //     cout << i << " -> ";
    //     for(int j = 0; j < graph[i].size(); j++){
    //         edge e = graph[i][j];
    //         cout << e.v << ", " << e.c << " || ";
    //     }
    //     cout << endl;
    // }

    vector<double> res;

    for(int i = 0; i < queries.size(); i++){
        string v1 = queries[i][0];
        string v2 = queries[i][1];
        double value;

        if((map.find(v1) == map.end()) || (map.find(v2) == map.end())){
            value = -1.0;
        } else {
            vector<bool> visited (size, false);
            found = false;
            value = findValue(graph, map, visited, v1, v2, 1);

            if(found == false){
                value = -1;
            }
        }

        res.push_back(value);
    }

    return res;
}

int main(){
    vector<vector<string>> equations;
    equations.push_back({"a", "b"});
    equations.push_back({"b", "c"});
    equations.push_back({"d", "e"});

    vector<double> values = {3,4,6};
    // vector<double> values = {2,3};

    vector<vector<string>> queries;
    queries.push_back({"e", "a"});

    vector<double> res = calcEquation(equations, values, queries);

    for(int i = 0; i < res.size(); i++){
        cout << setprecision (1) << fixed << res[i] << endl;
    }
}