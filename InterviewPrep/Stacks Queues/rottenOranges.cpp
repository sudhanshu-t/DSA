#include <iostream>
#include <vector>
#include <queue>
#include <climits>

// 0 - empty/obstacle, 1 - fresh, 2 - rotten

using namespace std;

class helper{
    public:
    int i;
    int j;
    int time;

    helper(int i, int j, int t){
        this->i = i;
        this->j = j;
        this->time = t;
    }
};

bool isValid(vector<vector<int>>& board, int i, int j, vector<vector<bool>>& visited){
    if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
        return false;

    if(board[i][j] == 0 || board[i][j] == 2 || visited[i][j] == true){
        return false;
    }

    return true;
}

int rottenOranges(vector<vector<int>>& board){
    queue<helper> q;
    int freshCount = 0;
    int extra = 0;
    int minTime = INT_MIN;

    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 1){
                freshCount++;
            }
            else if(board[i][j] == 2){
                q.push(helper (i, j, 0));
                extra++;
            }
        }
    }

    vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));

    while(q.size() != 0){
        helper front = q.front();
        q.pop();
        
        if(visited[front.i][front.j] == true){
            continue;
        } else {
            visited[front.i][front.j] = true;
            if(board[front.i][front.j] == 1){
                freshCount--;
            }
        }

        if(front.time > minTime){
            minTime = front.time;
        }

        if(isValid(board, front.i-1, front.j, visited)){
            q.push(helper (front.i-1, front.j, front.time + 1));
        }

        if(isValid(board, front.i+1, front.j, visited)){
            q.push(helper (front.i+1, front.j, front.time + 1));
        }

        if(isValid(board, front.i, front.j-1, visited)){
            q.push(helper (front.i, front.j-1, front.time + 1));
        }

        if(isValid(board, front.i, front.j+1, visited)){
            q.push(helper (front.i, front.j+1, front.time + 1));
        }
    }

    // cout << freshCount << " " << extra << endl;
    // cout << minTime << endl;
    if(freshCount != 0){
        return -1;
    }

    return minTime;
}

int main(int argc, char** argv){
    // vector<vector<int>> board = {
    //     {0,1,0,0,0,1,0},
    //     {1,1,1,0,0,1,1},
    //     {0,2,0,0,0,1,0},
    //     {0,0,0,1,1,1,0},
    //     {0,1,0,2,1,0,0},
    //     {2,1,0,0,1,1,0},
    //     {0,1,1,0,0,0,0},
    //     {0,0,1,1,1,1,0}
    // };

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr (n, vector<int> (m, 0));

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            cin >> arr[i][j];
        }
    }

    cout << rottenOranges(arr) << endl;
}