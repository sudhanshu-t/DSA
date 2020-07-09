#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    int rmz = INT_MIN;
    string ns;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            rmz = max(rmz, i);
        } else if (rmz != INT_MIN) {
            ns = s.substr(0, i) + '0' + s.substr(rmz + 1);
        }
    }

    return (ns.size() == 0) ? s : ns;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
}