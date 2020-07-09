#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> f (k);
        for (int i = 0; i < k; i++) {
            cin >> f[i];
        }

        sort(a.begin(), a.end());
        sort(f.begin(), f.end(), greater<int>());

        vector<vector<int>> g (k);
        int idx = 0;
        for (int i = 0; i < f.size(); i++) {
            for (int j = 0; j < f[i] - 1; j++) {
                g[i].push_back(a[idx++]);
            }
        }

        for (int i = 1; i <= k; i++) {
            g[i - 1].push_back(a[n - (k - i + 1)]);
        }

        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += g[i][0] + g[i][g[i].size() - 1];
        }

        cout << sum << endl;
    }
}