#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b (n, -1);
    unordered_set<int> set;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            b[i] = a[i - 1];
            set.insert(a[i - 1]);
        }
    }

    set.insert(a[n - 1]);

    int m = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            while (set.find(m) != set.end()) {
                m++;
            }

            b[i] = m;
            set.insert(m);
        }
    }

    for (int i: b) cout << i << " ";
    cout << endl;
}