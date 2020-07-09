#include <bits/stdc++.h>
#include <climits>
#include <vector>
#include <list>

using namespace std;

class Cell{
public:
    int i;
    int j;

    Cell(int i, int j){
        this->i = i;
        this->j = j;
    }
};

bool is_valid(vector<vector<int>>& g, int i, int j){
    if(i < 0 || i >= g.size() || j < 0 || j >= g[i].size()){
        return false;
    }
    if(g[i][j] != 1){
        return false;
    }

    return true;
}

int get_comp_size(vector<vector<int>>& grid, int i, int j){
    list<Cell> q;
    q.push_back(Cell (i, j));
    int size = 0;
    
    while(q.size() > 0){
        Cell front = q.front();
        q.pop_front();

        if(grid[front.i][front.j] == 1){
            grid[front.i][front.j] = 2;
        } else {
            continue;
        }

        size++;

        if(is_valid(grid, front.i + 1, front.j)){
            q.push_back(Cell (front.i + 1, front.j));
        }
        if (is_valid(grid, front.i - 1, front.j)) {
          q.push_back(Cell (front.i - 1, front.j));
        }
        if(is_valid(grid, front.i, front.j + 1)){
            q.push_back(Cell (front.i, front.j + 1));
        }
        if (is_valid(grid, front.i, front.j - 1)) {
          q.push_back(Cell (front.i, front.j - 1));
        }

        // Diagonals
        if(is_valid(grid, front.i + 1, front.j + 1)){
            q.push_back(Cell (front.i + 1, front.j + 1));
        }
        if (is_valid(grid, front.i - 1, front.j - 1)) {
          q.push_back(Cell (front.i - 1, front.j - 1));
        }
        if(is_valid(grid, front.i - 1, front.j + 1)){
            q.push_back(Cell (front.i - 1, front.j + 1));
        }
        if (is_valid(grid, front.i + 1, front.j - 1)) {
          q.push_back(Cell (front.i + 1, front.j - 1));
        }
    }

    return size;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    int max_size = INT_MIN;
    int size = 0;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1){
                size = get_comp_size(grid, i, j);
                if(size > max_size){
                    max_size = size;
                }
            }
        }
    }

    return size;
}

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 1, 1},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    cout << maxRegion(grid) << endl;

    return 0;
}
