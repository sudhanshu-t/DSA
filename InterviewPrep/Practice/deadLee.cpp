#include <bits/stdc++.h>
using namespace std;

int main() {
       int n, m;
       cin >> n >> m;

       vector<int> w (n + 1);
       for (int i = 1; i <= n; i++) {
              cin >> w[i];
       }

       unordered_map<int, int> r;
       unordered_map<int, vector<int>> f;
       vector<vector<int>> c (m + 1, vector<int> (2));
       
       for (int i = 1; i <= m; i++) {
              int a, b;
              cin >> a >> b;
              r[a]++;
              r[b]++;
              
              f[a].push_back(i);
              f[b].push_back(i);

              c[i][0] = a;
              c[i][1] = b;
       }

       bool ok = false;
       for (int i = 1; i <= n; i++) {
              if (r[i] <= w[i]) {
                     ok = true;
                     break;
              }
       }

       if (!ok) {
              cout << "DEAD" << endl;
              return 0;
       }

       list<int> ans;
       unordered_set<int> seen;
       for (int i = 1; i <= n; i++) {
              if (r[i] <= w[i]) {
                     for (int j = 0; j < f[i].size(); j++) {
                            if (seen.find(f[i][j]) == seen.end()) {
                                   ans.push_front(f[i][j]);
                                   seen.insert(f[i][j]);
                                   
                                   r[c[f[i][j]][0]]--;
                                   r[c[f[i][j]][1]]--;
                            }
                     }
              }
       }

       for (auto itr = ans.begin(); itr != ans.end(); itr++) {
              cout << *itr << " ";
       }
       cout << endl;
}