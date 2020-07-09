#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& g, int i, int j){
    g[i].push_back(j);
}

int helper(vector<vector<int>>& g, int src){
    int ans = 0;
    for(int i = 0; i < g[src].size(); i++){
        ans = max(ans, helper(g, g[src][i]));
    }

    return ans+1;
}

int getAns(vector<pair<int, int>>& input, int N){
    vector<vector<int>> g (N+1);
    for(int i = 0; i < input.size(); i++){
        addEdge(g, input[i].second, input[i].first);
    }

    int myMax = INT_MIN;
    for(int i = 1; i <= N; i++){
        int val = helper(g, i);
        myMax = max(myMax, val);
    }

    return myMax;
}

int main(){
    string str;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        getline(cin, str);
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> input(m);
        for(int j = 0; j < m; j++){
            cin >> input[j].first;
            cin >> input[j].second;
        }

        cout << "Case #" << i << " " << getAns(input, n) << endl;
    }
}