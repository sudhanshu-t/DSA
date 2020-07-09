#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& g, int s, vector<bool>& seen, set<int>& ans, int csf) {
       seen[s] = true;
       if (csf == 2) {
              ans.insert(s);
              // cout << "Adding " << s << endl;
              return;
       }
       
       for (int i = 0; i < g[s].size(); i++) {
              solve(g, g[s][i], seen, ans, csf + 1);
       }
}

int main() {
       int t;
       cin >> t;
       while (t--) {
              int n, m;
              cin >> n >> m;

              vector<vector<int>> g (n + 1);

              for (int  i = 0; i < m; i++) {
                     int a, b;
                     cin >> a >> b;
                     g[a].push_back(b);
              }

              set<int> ans;
              vector<bool> visited (n + 1);
              for (int i = 1; i <= n; i++) {
                     if (!visited[i]) solve(g, i, visited, ans, 0);
              }

              if (ans.size() > 4 * n / 7) {
                     cout << 4 * n / 7 << endl;
              } else {
                     cout << ans.size() << endl;
              }
              
              int idx = 0;
              for (auto itr: ans) {
                     idx++;
                     if (idx > 4 * n / 7) {
                            break;
                     }
                     
                     cout << itr << " ";
              }
              cout << endl;
       }

       return 0;
}