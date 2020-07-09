#include <bits/stdc++.h>
using namespace std;

int T;

void dfs(int s, int p, int d, vector<vector<int>>& g, vector<int>& dep, vector<int>& par, vector<int>& tin, vector<int>& tout) {
    par[s] = p;
    tin[s] = T++;
    dep[s] = d;

    // cout << g[s].size() << endl;

    for (int v: g[s]) {
        if (v == p) continue;
        dfs(v, s, d + 1, g, dep, par, tin, tout);
    }
    
    tout[s] = T++;
}

bool isAnc(int v, int u, vector<int>& tin, vector<int>& tout) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
    int n, m;
    cin >> n >> m;
    T = 0;
    vector<vector<int>> g (n + 1);
    vector<int> par (n + 1);
    vector<int> tin (n + 1), tout (n + 1);
    vector<int> dep (n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1, 0, g, dep, par, tin ,tout);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> queries (k);
        for (int j = 0; j < k; j++) {
            cin >> queries[j];
            queries[j];
        }

        int fv = queries[0];
        for (int q: queries) {
            if (dep[q] > dep[fv]) fv = q;
        }

        for (int &q: queries) {
            if (fv == q) continue;
            if (par[q] != -1) {
                q = par[q];
            }
        }

        bool ok = true;
        for (int q: queries) {
            ok &= isAnc(q, fv, tin, tout);
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}