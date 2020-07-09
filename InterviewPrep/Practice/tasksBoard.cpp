#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int n = s.size();

        int m;
        cin >> m;
        vector<int> b (m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        vector<vector<int>> groups;
        while (true) {
            vector<int> pos;
            for (int i = 0; i < m; i++) {
                if (b[i] == 0) {
                    pos.push_back(i);
                }
            }

            if (pos.size() == 0) break;

            groups.push_back(pos);
            for (int i = 0; i < m; i++) {
                if (b[i] == 0) b[i] = INT_MAX;
                else {
                    for (int j = 0; j < pos.size(); j++) {
                        b[i] -= abs(i - pos[j]);
                    }
                }
            }
        }

        string t (m, '?');
        map<char, int> counts;
        for (int i = 0; i < s.size(); i++) {
            counts[s[i]]++;
        }
        
        auto j = counts.rbegin();
        for (auto g: groups) {
            while (j->second < g.size()) {
                j++;
            }

            for (auto pp: g) {
                t[pp] = j->first;
            }

            j++;
        }

        cout << t << endl;
    }
}