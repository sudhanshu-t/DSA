#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> map;

        bool ok = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (map.find(x) == map.end()) {
                map[x] = i;
            } else {
                if (i - map[x] > 1) {
                    ok = true;
                }
            }
        }

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}