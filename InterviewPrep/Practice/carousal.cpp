#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& type) {
    if (count(type.begin(), type.end(), type[0]) == n) {
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    
    if (n % 2 == 0) {
        cout << 2 << endl;
        for (int i = 0; i < n; i++) {
            cout << i % 2 + 1 << " ";
        }
        cout << endl;
        return;
    }

    vector<int> col (n);
    for (int i = 0; i < n; i++) {
        if (type[i] == type[(i + 1) % n]) {
            for (int pos = i + 1, j = 0; pos < n; pos++, j ^= 1) {
                col[pos] = j + 1;
            }

            for (int pos = i, j = 0; pos >= 0; pos--, j ^= 1) {
                col[pos] = j + 1;
            }

            cout << 2 << endl;
            for (int i: col) {
                cout << i << " ";
            }
            cout << endl;

            return;
        }
    }

    cout << 3 << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << i % 2 + 1 << " ";
    }
    cout << 3 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> type (n);
        for (int i = 0; i < n; i++) {
            cin >> type[i];
        }

        solve(n, type);
    }
}