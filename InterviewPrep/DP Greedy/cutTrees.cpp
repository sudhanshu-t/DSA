#include <bits/stdc++.h>
using namespace std;

class cell{
public:
    int i;
    int j;
    int d;
    cell(int i, int j, int d){
        this->i = i;
        this->j = j;
        this->d = d;
    }
};

int cutOffTree(vector<vector<int>>& forest) {
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<cell> q;
    unordered_map<int, int> map;
    vector<vector<bool>> visited (forest.size(), vector<bool> (forest[0].size(), false));

    for(int i = 0; i < forest.size(); i++){
        for(int j = 0; j < forest[0].size(); j++){
            if(forest[i][j] > 1){
                pq.push(forest[i][j]);
            }
        }
    }
    
    int trees = pq.size();
    
    q.push(cell(0,0,0));
    
    int num = pq.top();
    pq.pop();
    
    while(q.size() != 0){
        cell c = q.front();
        q.pop();
        
        if(visited[c.i][c.j] == false){
            visited[c.i][c.j] = true;
        } else {
            continue;
        }
        
        if(forest[c.i][c.j] == num){
            // cout << num << " added with " << c.d <<  endl;
            map[num] = c.d;
            while(!q.empty()){
                q.pop();
            }
            
            c.d = 0;
            forest[c.i][c.j] = 1;
            vector<vector<bool>> temp (visited.size(), vector<bool> (visited[0].size(), false));
            visited = temp;
            visited[c.i][c.j] = true;
            if(pq.size() != 0){
                num = pq.top();
                pq.pop();
            }

            // cout << "New num is " << num << endl;
        }
        
        // T
        if(c.i-1 >= 0 && forest[c.i-1][c.j] != 0 && visited[c.i-1][c.j] == false){
            // cout << "Adding " << forest[c.i-1][c.j] << endl;
            q.push(cell(c.i-1, c.j, c.d+1));
        }
        // L
        if(c.j-1 >= 0 && forest[c.i][c.j-1] != 0 && visited[c.i][c.j-1] == false){
            // cout << "Adding " << forest[c.i][c.j-1] << endl;
            q.push(cell(c.i, c.j-1, c.d+1));
        }
        // D
        if(c.i+1 < forest.size() && forest[c.i+1][c.j] != 0 && visited[c.i+1][c.j] == false){
            // cout << "Adding " << forest[c.i+1][c.j] << endl;
            q.push(cell(c.i+1, c.j, c.d+1));
        }
        // R
        if(c.j+1 < forest[0].size() && forest[c.i][c.j+1] != 0 && visited[c.i][c.j+1] == false){
            // cout << "Adding " << forest[c.i][c.j+1] << endl;
            q.push(cell(c.i, c.j+1, c.d+1));
        }
    }

    if(map.size() != trees){
        return -1;
    }

    int ans = 0;
    for(auto itr: map){
        ans += itr.second;
    }

    return ans;
}

int main(){
    vector<vector<int>> forest = {
        {1,1,12},
        {1,0,10},
        {7,0,100}
    };
    cout << cutOffTree(forest) << endl;
}