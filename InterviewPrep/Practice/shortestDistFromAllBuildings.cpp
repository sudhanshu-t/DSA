#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Pair{
public:
    int i, j, d;
    Pair(int i, int j, int d){
        this->i = i;
        this->j = j;
        this->d = d;
    }
};

bool isValid(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
        return false;
    }
    
    if(grid[i][j] == -1 || grid[i][j] == -2){
        return false;
    }

    if(visited[i][j] == 1){
        return false;
    }
    
    return true;
}
    
int bReach = 0;
void poss(vector<vector<int>>& grid, int i, int j){
    if(grid[i][j] == 1){
        bReach++;
        cout << "Found at: " << i << ", " << j << endl;
        return;
    }
    
    grid[i][j] = -1;

    for (auto &&i : grid){
        for (auto &&j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "Checking for: " << i-1 << ", " << j << endl;

    if(i-1 >= 0 && (grid[i-1][j] == 1 || grid[i-1][j] == 0)){
        cout << "Going to: " << i-1 << ", " << j << endl;
        poss(grid, i-1, j);
    }
    
    cout << "Checking for: " << i+1 << ", " << j << endl;
    if(i+1 < grid.size() && (grid[i+1][j] == 1 || grid[i+1][j] == 0)){
        cout << "Going to: " << i+1 << ", " << j << endl;
        poss(grid, i+1, j);
    }
    
    cout << "Checking for: " << i<< ", " << j-1 << endl;
    if(j-1 >= 0 && (grid[i][j-1] == 1 || grid[i][j-1] == 0)){
        cout << "Going to: " << i << ", " << j-1<< endl;
        poss(grid, i, j-1);
    }
    
    cout << "Checking for: " << i << ", " << j+1 << endl;
    if(j+1 < grid[0].size() && (grid[i][j+1] == 1 || grid[i][j+1] == 0)){
        cout << "Going to: " << i << ", " << j+1 << endl;
        poss(grid, i, j+1);
    }
}

int shortestDistance(vector<vector<int>>& grid) {
    vector<vector<int>> gridCpy = grid;
    bool possible = false;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 0){
                possible = true;
            }
        }
    }
    
    if(!possible){
        return -1;
    }
    
    int bCount = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1 || grid[i][j] == 2){
                if(grid[i][j] == 1){
                    bCount++;
                }
                grid[i][j] = -grid[i][j];
            }
        }
    }

    for (auto &&i : grid){
        for (auto &&j : i){
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == -1){
                queue<Pair> q;
                q.push(Pair (i, j, 0));

                vector<vector<int>> visited (grid.size(), vector<int> (grid[0].size(), 0));
                
                while(!q.empty()){
                    Pair front = q.front();
                    q.pop();

                    if(grid[front.i][front.j] == -1){
                        
                    } else {
                        grid[front.i][front.j] += front.d;
                    }

                    if(isValid(front.i + 1, front.j, grid, visited)){
                        q.push(Pair(front.i + 1, front.j, front.d + 1));
                        visited[front.i+1][front.j] = 1;
                    }
                    if(isValid(front.i - 1, front.j, grid, visited)){
                        q.push(Pair(front.i - 1, front.j, front.d + 1));
                        visited[front.i-1][front.j] = 1;
                    }
                    if(isValid(front.i, front.j + 1, grid, visited)){
                        q.push(Pair(front.i, front.j + 1, front.d + 1));
                        visited[front.i][front.j+1] = 1;
                    }
                    if(isValid(front.i, front.j - 1, grid, visited)){
                        q.push(Pair(front.i, front.j - 1, front.d + 1));
                        visited[front.i][front.j-1] = 1;
                    }
                }
            } else {
                continue;
            }
        }
    }
    
    int minDist = INT_MAX, minI, minJ;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == -1 || grid[i][j] == -2){
                continue;
            } else {
                if(grid[i][j] < minDist){
                    minDist = grid[i][j];
                    minI = i;
                    minJ = j;
                }
            }
        }
    }

    cout << "Min Dist: " << minDist << endl;
    for (auto &&i : grid){
        for (auto &&j : i){
            cout << j << "  ";
        }
        cout << endl;
    }
    // cout << minI << ", " << minJ << endl;
    
    poss(gridCpy, minI, minJ);
    cout << bReach << " " << bCount << endl;
    if(bReach != bCount){
        return -1;
    }
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 0){
                possible = false;
            }
        }
    }
    
    if(!possible){
        return -1;
    }
    
    return minDist;
}

int main(){
    vector<vector<int>> grid = {
        {1,1,1,1,1,0},
        {0,0,0,0,0,1},
        {0,1,1,0,0,1},
        {1,0,0,1,0,1},
        {1,0,1,0,0,1},
        {1,0,0,0,0,1},
        {0,1,1,1,1,0}
    };
    // vector<vector<int>> grid = {{1,1,0,0},{0,0,0,1},{0,1,1,0}};

    int res = shortestDistance(grid);
    cout << res << endl;
}