#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class helper{
public:
    int i;
    int j;
    
    helper(int i, int j){
        this->i = i;
        this->j = j;
    }
};

bool isValid(vector<vector<char>>& grid, int i, int j){
    if(i >= grid.size() || j >= grid[0].size()){
        return false;
    }
    
    if(grid[i][j] != '1'){
        return false;
    }
    
    return true;
}

void visit(vector<vector<char>>& grid, int i, int j){
    queue<helper> q;
    
    q.push(helper(i, j));
    
    while(q.size() != 0){
        helper front = q.front();
        q.pop();
        
        if(grid[front.i][front.j] != '2'){
            grid[front.i][front.j] = '2';
        } else {
            continue;
        }
        
        if(isValid(grid, front.i + 1, front.j)){
            q.push(helper(front.i + 1, front.j));
        }
        
        if(isValid(grid, front.i - 1, front.j)){
            q.push(helper(front.i - 1, front.j));
            
        }
        
        if(isValid(grid, front.i, front.j + 1)){
            q.push(helper(front.i, front.j + 1));
            
        }
        
        if(isValid(grid, front.i, front.j - 1)){
            q.push(helper(front.i, front.j - 1));
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                res++;
                visit(grid, i, j);

                for(int x = 0; x < grid.size(); x++){
                    for(int y = 0; y < grid[0].size(); y++){
                        cout << grid[x][y] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    
    return res;
}

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << numIslands(grid) << endl;
}