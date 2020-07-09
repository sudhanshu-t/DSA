#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class helper{
public:
    int i, j, v;
    helper(int i, int j, int v){
        this->i = i;
        this->j = j;
        this->v = v;
    }
};

bool isValid(int i, int j, vector<vector<int>>& rooms){
    if(i >= rooms.size() || j >= rooms[0].size()){
        return false;
    }
    
    if(rooms[i][j] == -1 || rooms[i][j] == 0){
        return false;
    }
    
    return true;
}

void wallsAndGates(vector<vector<int>>& rooms) {
    queue<helper> q;
    
    for(int i = 0; i < rooms.size(); i++){
        for(int j = 0; j < rooms[0].size(); j++){
            if(rooms[i][j] == 0){
                q.push(helper (i, j, 0));
            }
        }
    }
    
    while(!q.empty()){
        helper front = q.front();
        q.pop();
        
        if(rooms[front.i][front.j] == 0 || rooms[front.i][front.j] == INT_MAX){
            rooms[front.i][front.j] = front.v;
        } else {
            continue;
        }
        
        if(isValid(front.i+1, front.j, rooms)){
            q.push(helper (front.i+1, front.j, front.v + 1));
        }
        
        if(isValid(front.i-1, front.j, rooms)){
            q.push(helper (front.i-1, front.j, front.v + 1));
        }
        
        if(isValid(front.i, front.j+1, rooms)){
            q.push(helper (front.i, front.j+1, front.v + 1));
        }
        
        if(isValid(front.i, front.j-1, rooms)){
            q.push(helper (front.i, front.j-1, front.v + 1));
        }
    }
}

int main(){
    vector<vector<int>> rooms = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };

    wallsAndGates(rooms);
    for (auto &&i : rooms)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;        
    }
    
}