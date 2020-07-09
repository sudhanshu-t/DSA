#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int h = 0, v = 0;

        queue<tuple<int, int, int>> q;
        map<tuple<int, int>, int> pos;
        int st = -1, end = -1;
        int len = INT_MAX;
        int idx = 0;
        q.push(make_tuple(0, 0, 0));
        while (!q.empty()) {
            auto [x, y, i] = q.front(); q.pop();

            if (pos.find(make_tuple(x, y)) == pos.end()) {
                pos[make_tuple(x, y)] = i + 1;
            } else {
                // cout << x << " " << y << endl;
                // cout << len << " " << i - pos[make_tuple(x, y)] + 1 << endl;
                if (len > i - pos[make_tuple(x, y)] + 1) {
                    len = i - pos[make_tuple(x, y)] + 1;

                    st = pos[make_tuple(x, y)];                    
                    end = i;
                }

                pos[make_tuple(x, y)] = i + 1;
            }

            if (idx >= n) continue;

            if (s[idx] == 'L') {
                // cout << "Adding " << x - 1 << " " << y << " " << i + 1 << endl;
                q.push(make_tuple(x - 1, y, i + 1));
            } else if (s[idx] == 'R') {
                // cout << "Adding " << x + 1 << " "<< y << " " << i + 1 << endl;
                q.push(make_tuple(x + 1, y, i + 1));
            } else if (s[idx] == 'U') {
                // cout << "Adding " << x << " " << y + 1 << " " << i + 1 << endl;
                q.push(make_tuple(x, y + 1, i + 1));
            } else {
                // cout << "Adding " << x << " " << y - 1 << " " << i + 1 << endl;
                q.push(make_tuple(x, y - 1, i + 1));
            }

            idx++;
        }

        if (st == -1 || end == -1) {
            cout << -1 << endl;
            continue;
        }

        cout << st << " " << end << endl;
    }

    return 0;
}