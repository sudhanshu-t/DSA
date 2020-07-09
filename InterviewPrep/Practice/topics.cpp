#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;
    vector<int> a (n);
    vector<int> b (n);
    vector<int> c (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end());
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(c.begin(), c.begin() + i, 1 - c[i]) - c.begin();
        // cout << c[i] << " " << j << endl;
        count += i - j;
    }

    cout << count << endl;
}