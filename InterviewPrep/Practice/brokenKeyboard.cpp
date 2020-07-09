#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;

    unordered_set<char> set;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        set.insert(c);
    }

    long long len = 0;
    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (set.find(a[i]) == set.end()) {
            ans += len * (len + 1) / 2;
            len = 0;
        } else {
            len++;
        }
    }

    if (set.find(a[a.size() - 1]) != set.end()) {
        ans += len * (len + 1) / 2;
    }

    cout << ans << endl;
}