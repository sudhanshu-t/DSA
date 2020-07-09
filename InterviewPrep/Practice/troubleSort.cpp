#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        vector<int> type (n);

        int z = 0, o = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> type[i];
            if (type[i] == 0) z++;
            else o++;
        }

        if (o != 0 && z != 0) {
            cout << "Yes" << endl;
            continue;
        }

        bool ans = true;
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] > a[i + 1]) {
                ans = false;
                break;
            }
        }

        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}