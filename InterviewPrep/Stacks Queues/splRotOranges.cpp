#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

class Orange{
    public:
    int rotVal;
    int i;
    int j;
    int time;
    
    Orange(int rv, int i, int j, int time){
        rotVal = rv;
        this->i = i;
        this->j = j;
        this->time = time;
    }
};

bool isValid(vector<vector<int>>& table, vector<vector<bool>>& visited, int i, int j, int rv){
    if(i < 0 || i >= table.size() || j < 0 || j >= table[0].size()){
        return false;
    }
    
    if(table[i][j] == 0){
        return false;
    }
    
    if(rv == 2 && table[i][j] == 3){
        return false;
    }
    
    if(rv == 3 && table[i][j] == 2){
        return false;
    }
    
    if(visited[i][j] == true){
        return false;
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<vector<int>> table (101, vector<int> (101, 0));
    vector<vector<bool>> visited (101, vector<bool> (101, false));
    
    int minTime = INT_MIN;
    int r, c;
    cin >> r >> c;
    
    int freshC = 0;
    int extra = 0;

    queue<Orange> q;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> table[i][j];
            if(table[i][j] == 1){
                freshC++;
            } else if(table[i][j] == 2 || table[i][j] == 3){
                q.push(Orange (table[i][j], i, j, 0));
                extra++;
            }
        }
    }

    // cout << "FC " << freshC << endl;
    
    while(q.size() > 0){
        Orange front = q.front();
        q.pop();
        
        if(visited[front.i][front.j] == true){
            continue;
        } else {
            visited[front.i][front.j] = true;

            // if(front.rotVal != 2 && front.rotVal != 3)
                freshC--;
        }
        
        minTime = max(minTime, front.time);
        
        int i = front.i;
        int j = front.j;
        if(isValid(table, visited, front.i+1, front.j, front.rotVal)){
            // if(front.rotVal == 2)
                // cout << front.rotVal << " kills " << i+1 << j << endl;
                q.push(Orange (front.rotVal, front.i+1, front.j, front.time + 1));
        }
        if(isValid(table, visited, front.i-1, front.j, front.rotVal)){
            // if(front.rotVal == 2)
                // cout << front.rotVal << " kills " << i-1 << j << endl;

                q.push(Orange (front.rotVal, front.i-1, front.j, front.time + 1));
            
        }
        if(isValid(table, visited, front.i, front.j+1, front.rotVal)){
            // if(front.rotVal == 2)
                q.push(Orange (front.rotVal, front.i, front.j+1, front.time + 1));
                // cout << front.rotVal << " kills " << i << j+1 << endl;

            
        }
        if(isValid(table, visited, front.i, front.j-1, front.rotVal)){
            // if(front.rotVal == 2)
                q.push(Orange (front.rotVal, front.i, front.j-1, front.time + 1));
                // cout << front.rotVal << " kills " << i << j-1 << endl;

            
        }
        
        if(front.time == 3){
            if(isValid(table, visited, front.i+2, front.j, front.rotVal)){
            // if(front.rotVal == 2)
                q.push(Orange (front.rotVal, front.i+2, front.j, front.time + 1));
                // cout << front.rotVal << " kills " << i+2 << j << endl;

                
            }
            if(isValid(table, visited, front.i-2, front.j, front.rotVal)){
                // if(front.rotVal == 2)
                    q.push(Orange (front.rotVal, front.i-2, front.j, front.time + 1));
                // cout << front.rotVal << " kills " << i-2 << j << endl;

                
            }
            if(isValid(table, visited, front.i, front.j+2, front.rotVal)){
                // if(front.rotVal == 2)
                    q.push(Orange (front.rotVal, front.i, front.j+2, front.time + 1));
                // cout << front.rotVal << " kills " << i << j+2 << endl;

                
            }
            if(isValid(table, visited, front.i, front.j-2, front.rotVal)){
                // if(front.rotVal == 2)
                    q.push(Orange (front.rotVal, front.i, front.j-2, front.time + 1));
                // cout << front.rotVal << " kills " << i << j+2 << endl;

                
            }
        }
    }
    
    if(freshC + extra == 0){
        cout << minTime << endl;
    } else {
        cout << "-1" << endl;
        // cout << freshC << endl;
    }
    
    
    
    return 0;
}
