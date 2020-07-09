#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a (n, vector<int> (n));

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = n - 1; j >= 0; j--) {
                int d = x % 10;
                x = x / 10;
                a[i][j] = d;
            }
        }

        bool notPos = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    if (i == n - 1 || j == n - 1) continue;

                    if (i + 1 < n && a[i + 1][j] == 0) {
                        if (j == n - 1) continue;

                        if (a[i][j + 1] == 0) {
                            notPos = true;
                            break;
                        }
                    }

                    if (j + 1 < n && a[i][j + 1] == 0) {
                        if (i == n - 1) continue;

                        if (a[i + 1][j] == 0) {
                            notPos = true;
                            break;
                        }
                    }
                }
            }

            if (notPos) break;
        }

        if (notPos) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}