#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
vector<vector<int>> g;
vector<int> ans;

void solve(vector<int>& st, vector<int>& end) {
    dist = vector<int> (ans.size(), INT_MAX);
    queue<int> q;
    for (int i: st) {
        q.push(i);
        dist[i] = 0;
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (int i = 0; i < g[cur].size(); i++) {
            if (dist[g[cur][i]] == INT_MAX) {
                q.push(g[cur][i]);
                dist[g[cur][i]] = dist[cur] + 1;
            }
        }
    }

    for (int i: end) {
        if (dist[i] != INT_MAX) {
            ans[i] = dist[i];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    vector<int> even;
    vector<int> odd;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) odd.push_back(i);
        else even.push_back(i);
    }

    g = vector<vector<int>> (2 * n);
    for (int i = 0; i < n; i++) {
        int l = i - a[i];
        int r = i + a[i];

        if (l >= 0) g[l].push_back(i);
        if (r < n) g[r].push_back(i);
    }

    ans = vector<int> (n, -1);
    solve(even, odd);
    solve(odd, even);
    
    for (int i: ans) cout << i << " ";
    cout << endl;

    return 0;
}