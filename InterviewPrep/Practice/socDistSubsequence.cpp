#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a (n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1 || (a[i] >= a[i - 1] && a[i] >= a[i + 1]) || (a[i] <= a[i - 1] && a[i] <= a[i + 1])) {
                b.push_back(a[i]);
            }
        }

        cout << b.size() << endl;
        for (int i: b) {
            cout << i << " ";
        }
        cout << endl;
    }
}