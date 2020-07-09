#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < a.size(); i++) {
            cin >> a[i];
        }
        
        int e = 0, o = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) e++;
            else o++;
        }

        if (e % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }

        bool done = false;
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++) {
            if (a[i] + 1 == a[i + 1]) {
                cout << "YES" << endl;
                done = true;
                break;
            }
        }

        if (!done) cout << "NO" << endl;
    }
}