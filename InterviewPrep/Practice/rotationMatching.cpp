#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a (n), b (n);
    unordered_map<int, int> bmap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bmap[b[i]] = i;
    }

    unordered_map<int, int> shiftFr;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int j = bmap[a[i]];
        int shifts;
        if (j < i) {
            shifts = n + j - i;
        } else {
            shifts = j - i;
        }

        shiftFr[shifts]++;
        mx = max(mx, shiftFr[shifts]);
    }

    cout << mx << endl;
}