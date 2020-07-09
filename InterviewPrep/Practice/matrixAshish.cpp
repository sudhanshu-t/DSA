#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;

        vector<int> rows;
        vector<int> cols;

        vector<vector<int>> a (r, vector<int> (c));
        for (int i = 0; i < r; i++) {
            bool foundInRow = false;
            for (int j = 0; j < c; j++) {
                int x;
                cin >> x;
                a[i][j] = x;

                if (x == 1) {
                    foundInRow = true;
                }
            }

            if (!foundInRow) {
                rows.push_back(i);
            }
        }

        for (int j = 0; j < c; j++) {
            bool foundInCol = false;
            for (int i = 0; i < r; i++) {
                if (a[i][j] == 1) {
                    foundInCol = true;
                    break;
                }
            }

            if (!foundInCol) {
                cols.push_back(j);
            }
        }

        int v = min(rows.size(), cols.size());

        if (v % 2 == 0) {
            cout << "Vivek" << endl;
        } else {
            cout << "Ashish" << endl;
        }
    }
}