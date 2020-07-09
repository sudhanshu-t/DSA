#include <bits/stdc++.h>
using namespace std;

void solve(string s, int k) {
    string ans;
    sort(s.begin(), s.end());
    
    if (s[k - 1] != s[0]) {
        cout << s[k - 1] << endl;
        return;
    }

    cout << s[0];

    if (s[k] != s[s.size() - 1]) {
        for (int i = k; i < s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
        return;
    } else {
        int i = k;
        while (i < s.size()) {
            cout << s[i];
            i += k;
        }
        cout << endl;
        return;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (k == 1) {
            cout << s << endl;
            continue;
        }

        solve(s, k);
    }
}