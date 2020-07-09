#include <bits/stdc++.h>
using namespace std;

// . - 0, # - -1, G - 1, B - 2, visited - 3

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> a (r, vector<int> (c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char c;
                cin >> c;
                if (c == '.') {
                    a[i][j] = 0;
                } else if (c == '#') {
                    a[i][j] = -1;
                } else if (c == 'G') {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 2;
                }
            }
        }



        bool ans = true;
        int totalGoods = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == 1) {
                    totalGoods++;
                } else if (a[i][j] == 2) {
                    if (i - 1 >= 0 && a[i - 1][j] == 1) {
                        ans = false;
                        break;
                    }
                    if (i + 1 < r && a[i + 1][j] == 1) {
                        ans = false;
                        break;
                    }
                    if (j - 1 >= 0 && a[i][j - 1] == 1) {
                        ans = false;
                        break;
                    }
                    if (j + 1 < c && a[i][j + 1] == 1) {
                        ans = false;
                        break;
                    }

                    if (i - 1 >= 0 && a[i - 1][j] == 0) {
                        a[i - 1][j] = -1;
                    }
                    if (i + 1 < r && a[i + 1][j] == 0) {
                        a[i + 1][j] = -1;
                    }
                    if (j - 1 >= 0 && a[i][j - 1] == 0) {
                        a[i][j - 1] = -1;
                    }
                    if (j + 1 < c && a[i][j + 1] == 0) {
                        a[i][j + 1] = -1;
                    }
                }
            }

            if (ans == false) {
                break;
            }
        }

        if (totalGoods > 0 && ((r - 2 >= 0 && a[r - 2][c - 1] == 2) || (c - 2 >= 0 && a[r - 1][c - 2] == 2))) {
            cout << "No" << endl;
            continue;
        }

        // cout << "Ans = " << ans << endl;
        if (!ans) {
            cout << "No" << endl;
            continue;
        }


        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        queue<tuple<int, int>> q;
        q.push(make_tuple(r - 1, c - 1));

        int goodsRescued = 0;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            if (a[i][j] == 3) {
                continue;
            }

            if (a[i][j] == 1) {
                goodsRescued++;
            }

            a[i][j] = 3;

            if (i - 1 >= 0 && a[i - 1][j] != -1) {
                q.push(make_tuple(i - 1, j));
            }
            if (i + 1 < r && a[i + 1][j] != -1) {
                q.push(make_tuple(i + 1, j));
            }
            if (j - 1 >= 0 && a[i][j - 1] != -1) {
                q.push(make_tuple(i, j - 1));
            }
            if (j + 1 < c && a[i][j + 1] != -1) {
                q.push(make_tuple(i, j + 1));
            }
        }

        // for (int i = 0; i < r; i++) {
        //     for (int j = 0; j < c; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << totalGoods << " " << goodsRescued << endl;

        if (goodsRescued == totalGoods) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}