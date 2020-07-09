#include <bits/stdc++.h>
using namespace std;

bool hasValidPath(vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dirs = {
        {{0, -1}, {0, 1}},
        {{-1, 0}, {1, 0}},
        {{0, -1}, {1, 0}},
        {{0, 1}, {1, 0}},
        {{-1, 0}, {0, -1}},
        {{-1, 0}, {0, 1}}
    };
    
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size()));
    queue<vector<int>> q;
    q.push({0, 0});
    return true;
}

int main() {
    vector<vector<int>> grid;
    cout << hasValidPath(grid) << endl;
}