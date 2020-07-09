#include <bits/stdc++.h>
using namespace std;

long M = 998244353;
long ans = 0;

int getCountOfPairs(vector<vector<int>>& grid, int x, int y) {
    int rc = 0, cc = 0;
    for (int i = x + 1; i < grid.size(); i++) {
        if (grid[i][y] == 1) {
            cc++;
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--) {
        if (grid[i][y] == 1) {
            cc++;
            break;
        }
    }

    for (int j = y + 1; j < grid.size(); j++) {
        if (grid[x][j] == 1) {
            rc++;
            break;
        }
    }

    for (int j = y - 1; j >= 0; j--) {
        if (grid[x][j] == 1) {
            rc++;
            break;
        }
    }

    return rc + cc;
}

void count(vector<vector<int>>& grid, int n, int k, int pmsf, int rpsf, int lub) {
    if (rpsf == n) {
        if (pmsf == k) {
            ans = ((ans % M) + 1) % M;
        }
        return;
    }

    for (int i = lub + 1; i < n * n; i++) {
        int x = i / n;
        int y = i % n;
        grid[x][y] = 1;
        int pairsFormed = getCountOfPairs(grid, x, y);

        count(grid, n, k, pairsFormed, rpsf + 1, i);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid (n, vector<int> (n));
    count(grid, n, k, 0, 0, -1);

    cout << ans << endl;
}