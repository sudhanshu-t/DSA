#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int fib_mem(int n, int qb[]){
    if(n == 0 || n == 1){
        return n;
    }

    if(qb[n] != 0){
        return qb[n];
    }

    int fnm1 = fib_mem(n-1, qb);
    int fnm2 = fib_mem(n-2, qb);

    qb[n] = fnm1 + fnm2;

    return qb[n];
}

int climb_stairs(int n, int qb[]){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    if(qb[n] != 0){
        return qb[n];
    }
    
    int w1 = climb_stairs(n-1, qb);
    int w2 = climb_stairs(n-2, qb);
    int w3 = climb_stairs(n-3, qb);

    qb[n] = w1 + w2 + w3;

    return w1 + w2 + w3;
}

int climb_stairs_2(int n, int steps[], int qb[]){
    if(n == 0){
        return 1;
    }

    if(qb[n] != 0){
        return qb[n];
    }
    
    int ways = 0;
    for(int i = 1; i <= steps[n]; i++){
        if(steps[n-i] != 0 && n-i >= 0)
            ways +=  climb_stairs_2(n - i, steps, qb);
    }

    qb[n] = ways;

    return qb[n];
}

int stairs_2_tabulations(vector<int>& jump_size){
    vector<int> strg (jump_size.size(), 0);
    strg[0] = 1;
    for(int s = 1; s < jump_size.size(); s++){
        for(int js = 1; js <= jump_size[s]; js++){
            int i = s - js;

            if(i >= 0){
                strg[s] += strg[i];
            } else {
                break;
            }
        }
    }

    return strg[strg.size() - 1];
}

void min_no_steps(vector<int>& jump_size){
    vector<int> strg (jump_size.size(), INT_MAX);

    strg[0] = 0;

    for(int s = 1; s < jump_size.size(); s++){
        for(int js = 1; js <= jump_size[s]; js++){
            int i = s - js;

            if(i >= 0){
                strg[s] = min(strg[s], strg[i]);
            } else {
                break;
            }
        }

        if(strg[s] != INT_MAX)
            strg[s]++;
    }

    for(int i = 0; i < strg.size(); i++){
        cout << strg[i] << " ";
    }

    cout << endl;
    return;
}

// Prints all smallest paths
void print_smallest_path(vector<int>& jump_size, vector<int>& strg, int dest, string path){
    if(dest < 0){
        cout << path + to_string(0) << endl;
        return;
    }

    for(int i = 1; i <= jump_size[dest]; i++){
        if(strg[dest - i] + 1 == strg[dest]){
            print_smallest_path(jump_size, strg, dest-i, path + to_string(dest) + " ");
        }
    }
}

vector<vector<int>>* maze_min_cost(vector<vector<int>>& cost){
    vector<vector<int>>* strg = new vector<vector<int>>();

    for(int i = 0; i < cost.size(); i++){
        (*strg).push_back(vector<int> (cost[0].size(), 0));
    }

    (*strg)[(*strg).size() - 1][(*strg).size() - 1] = cost[cost.size() - 1][cost.size() - 1];
    for(int i = (*strg).size() - 1; i >= 0; i--){
        for(int j = (*strg)[i].size() - 1; j >= 0; j--){
            if(i+1 < (*strg).size() && j+1 < (*strg).size()){
                (*strg)[i][j] = min((*strg)[i+1][j], (*strg)[i][j+1]) + cost[i][j];
            } else if(i+1 < (*strg).size()){
                (*strg)[i][j] = (*strg)[i+1][j] + cost[i][j];
            } else if(j+1 < (*strg).size()){
                (*strg)[i][j] = (*strg)[i][j+1] + cost[i][j];
            } else {
                (*strg)[i][j] = cost[i][j];
            }
        }
    }

    return strg;
}

void print_min_cost_maze_path(vector<vector<int>> cost, vector<vector<int>>* strg, string path, int r, int c){
    if(r == (*strg).size() - 1 && c == (*strg)[0].size() - 1){
        cout << path << endl;
        return;
    }
    
    for(int i = r; i < (*strg).size(); i++){
        for(int j = c; j < (*strg).size(); j++){
            
            if(i+1 < cost.size() && j+1 < cost.size()){
                int mini = min((*strg)[i+1][j], (*strg)[i][j+1]);

                string s; int x, y;
                if(mini == (*strg)[i+1][j]){
                    s = "D";
                    x = i + 1;
                    y = j;
                } else {
                    s = "R";
                    x = i;
                    y = j + 1;
                }

                cout << "E Pre " << mini << " at " << x << ", " << y << endl;

                print_min_cost_maze_path(cost, strg, path + s + " ", x, y);

                cout << "E Post " << x << ", " << y << endl;
            } else if(i+1 >= cost.size()){
                print_min_cost_maze_path(cost, strg, path + "R ", i, j+1);
            } else if(j+1 >= cost.size()){
                print_min_cost_maze_path(cost, strg, path + "D ", i+1, j);
            }

            
            // if(i+1 < cost.size()){
            //     if((*strg)[i][j] - cost[i][j] == (*strg)[i+1][j]){
            //         print_min_cost_maze_path(cost, strg, path + "Down ", r + 1, c);
            //     }
            // } else if(j+1 < cost.size()){
            //     if((*strg)[i][j] - cost[i][j] == (*strg)[i][j+1]){
            //         print_min_cost_maze_path(cost, strg, path + "Right ", r, c + 1);
            //     }
            // }
            
            // if(i+1 < cost.size() && (*strg)[i][j] - cost[i][j] == (*strg)[i+1][j]){
            //     print_min_cost_maze_path(cost, strg, path + "Down ", r + 1, c);
            // } else if(j+1 < cost.size() && (*strg)[i][j] - cost[i][j] == (*strg)[i][j+1]){
            //     print_min_cost_maze_path(cost, strg, path + "Right ", r, c + 1);
            // }
        }
    }
}

int main(int argc, char** argv){
    // int qb[7] = {0};
    // cout << fib_mem(6, qb) << endl;
    
    // int arr[8] = {0};
    // cout << climb_stairs(7, arr) << endl;

    // int steps[9] = {1,2,3,1,0,2,0,2,4};
    // int qb[9] = {0};
    // cout << climb_stairs_2(8, steps, qb) << endl;

    // vector<int> jump_size = {1,2,3,2,0,2,0,2,4};
    // vector<int> strg = {0,1,1,2,-1,3,-1,4,4};
    // cout << stairs_2_tabulations(jump_size) << endl;
    // min_no_steps(jump_size);

    vector<vector<int>> cost {
        {2,6,5,1,3,4},
        {0,4,9,2,9,0},
        {4,8,1,0,6,5},
        {0,3,3,1,5,4},
        {1,2,7,0,6,9},
        {5,7,1,3,8,2}
    };

    vector<vector<int>>* strg = maze_min_cost(cost);

    for(int i = 0; i < strg->size(); i++){
        for(int j = 0; j < strg->at(i).size(); j++){
            cout << strg->at(i)[j] << " ";
        }

        cout << endl;
    }
    
    // print_smallest_path(jump_size, strg, 8, "");

    print_min_cost_maze_path(cost, strg, "", 0, 0);
}