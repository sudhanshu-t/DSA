#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(vector<vector<int>>& grid, int bn, vector<int>& map){
    if(map[bn] == bn){
        return bn;
    }
    
    return find(grid, map[bn], map);
}

vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    vector<int> map (m*n);
    vector<int> res;
    vector<vector<int>> grid (m, vector<int> (n));
    int setLeader = 0;
    
    for(int i = 0; i < positions.size(); i++){
        int x = positions[i][0];
        int y = positions[i][1];
        
        if(grid[x][y] == 1){
            res.push_back(setLeader);
            continue;
        } else {
            grid[x][y] = 1;
            int bn = x*n + y;
            map[bn] = bn;
            setLeader++;
            
            if(x-1 >= 0 && grid[x-1][y] == 1){
                int nbn = (x-1) * n + y;
                int sl = find(grid, nbn, map);
                
                if(sl != bn){
                    map[sl] = bn;
                    setLeader--;
                }
            }
            if(x+1 < grid.size() && grid[x+1][y] == 1){
                int nbn = (x+1) * n + y;
                int sl = find(grid, nbn, map);
                
                if(sl != bn){
                    map[sl] = bn;
                    setLeader--;
                }
            }
            if(y-1 >= 0 && grid[x][y-1] == 1){
                int nbn = (x) * n + y-1;
                int sl = find(grid, nbn, map);
                
                if(sl != bn){
                    map[sl] = bn;
                    setLeader--;
                }
            }
            if(y+1 < grid[0].size() && grid[x][y+1] == 1){
                int nbn = (x) * n + y+1;
                int sl = find(grid, nbn, map);
                
                if(sl != bn){
                    map[sl] = bn;
                    setLeader--;
                }
            }
        }
        
        res.push_back(setLeader);
    }
    
    return res;
}

int main(){
    vector<vector<int>> positions = {{0,1},{1,2},{2,1},{1,0},{0,2},{0,0},{1,1}};
    vector<int> res = numIslands2(3, 3, positions);

    for (auto &&i : res)
    {
        cout << i << endl;
    }

}