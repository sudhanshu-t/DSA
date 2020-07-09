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

void print_min_cost_maze_path(vector<vector<int>>* strg, string path, int r, int c){
    if(r == (*strg).size() - 1 && c == (*strg)[0].size() - 1){
        cout << path << endl;
        return;
    } else if(r == (*strg).size() - 1){
        print_min_cost_maze_path(strg, path + "H", r, c+1);
    } else if(c == (*strg)[0].size() - 1){
        print_min_cost_maze_path(strg, path + "V", r+1, c);
    } else {
        int myMin = min((*strg)[r+1][c], (*strg)[r][c+1]);

        if((*strg)[r+1][c] == myMin){
            print_min_cost_maze_path(strg, path + "V", r+1, c);
        }

        if((*strg)[r][c+1] == myMin){
            print_min_cost_maze_path(strg, path + "H", r, c+1);
        }
    }
}

int gold_mine(vector<vector<int>>& mine, int r){
    vector<vector<int>> strg (mine.size(), vector<int> (mine[0].size(), 0));

    for(int i = 0; i < mine.size(); i++){
        strg[i][mine[0].size()-1] = mine[i][mine[0].size()-1];
    }

    for(int j = strg[0].size()-2; j >= 0; j--){
        for(int i = 0; i < strg.size(); i++){
            int myMax;

            if(i == mine.size() - 1){
                myMax = max(strg[i][j+1], strg[i-1][j+1]);
            } else if(i == 0){
                myMax = max(strg[i][j+1], strg[i+1][j+1]);
            } else {
                myMax = max(max(strg[i-1][j+1], strg[i+1][j+1]), strg[i][j+1]);
            }

            strg[i][j] = myMax + mine[i][j];
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg[0].size(); j++){
            cout << strg[i][j] << "\t";
        }
        cout << endl;
    }

    return strg[r][0];
}

void print_subsets_targest_sum(vector<vector<int>>& strg, int r, int c, int arr[], int n, string psf){
    if(c == 0){
        cout << psf << endl;
        return;
    } else {
        if(strg[r-1][c] == true){
            print_subsets_targest_sum(strg, r-1, c, arr, n, "");
        }

        if(arr[r-1] <= c && strg[r-1][c - arr[r-1]] == true){
            print_subsets_targest_sum(strg, r-1, c - arr[r-1], arr, n, psf + to_string(arr[r-1]) + " ");
        }
    }
}

bool target_sum(int arr[], int n, int tar){
    vector<vector<int>> strg (n+1, vector<int> (tar+1, false));

    for(int i = 0; i < strg.size(); i++){
        strg[i][0] = true;
    }

    for(int j = 0; j < strg[0].size(); j++){
        strg[0][j] = false;
    }

    strg[0][0] = true;

    // Meaning of strg[i][j] - can i length array make a sum of j

    for(int i = 1; i < strg.size(); i++){
        for(int j = 1; j < strg[0].size(); j++){
            if(arr[i-1] > j){
                strg[i][j] = strg[i-1][j];
                continue;
            }

            if(strg[i-1][j] || strg[i-1][j - arr[i-1]]){
                strg[i][j] = true;
            }
        }
    }

    for(int i = 0; i < strg.size(); i++){
        for(int j = 0; j < strg[0].size(); j++){
            cout << strg[i][j] << " ";
        }
        cout << endl;
    }

    print_subsets_targest_sum(strg, n, tar, arr, n, "");
    return strg[n][tar];
}

int cc_perm_count(vector<int>& arr, int sum){
    vector<int> strg (sum + 1, 0);
    strg[0] = 1;

    for(int i = 1; i < strg.size(); i++){
        int ways = 0;
        for(int c = 0; c < arr.size(); c++){
            if(i >= arr[c]){
                ways += strg[i - arr[c]];
            }
        }
        strg[i] = ways;
    }

    for(int i = 0; i < strg.size(); i++){
        cout << i << " :- ways count = " << strg[i] << endl;
    }

    return strg[sum];
}

int cc_comb_count(vector<int>& arr, int sum){
    vector<int> strg (sum + 1, 0);
    strg[0] = 1;
    
    for(int c = 0; c < arr.size(); c++){
        for(int i = 1; i < strg.size(); i++){
            int ways = 0;

            if(i >= arr[c]){
                ways += strg[i - arr[c]];
            }
            strg[i] += ways;
        }
    }

    for(int i = 0; i < strg.size(); i++){
        cout << i << " :- ways count = " << strg[i] << endl;
    }

    return strg[sum];
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

    // vector<vector<int>> cost {
    //     {2,6,5,1,3,4},
    //     {0,4,9,2,9,0},
    //     {4,8,1,0,6,5},
    //     {0,3,3,1,5,4},
    //     {1,2,7,0,6,9},
    //     {5,7,1,3,8,2}
    // };

    // vector<vector<int>>* strg = maze_min_cost(cost);

    // for(int i = 0; i < strg->size(); i++){
    //     for(int j = 0; j < strg->at(i).size(); j++){
    //         cout << strg->at(i)[j] << " ";
    //     }

    //     cout << endl;
    // }
    
    // print_smallest_path(jump_size, strg, 8, "");

    // print_min_cost_maze_path(strg, "", 0, 0);

    // vector<vector<int>> mine {
    //     {2,5,0,1,3},
    //     {1,5,4,2,9},
    //     {4,2,8,1,7},
    //     {0,1,3,5,4},
    //     {3,4,8,2,4},
    //     {2,0,6,3,7}
    // };

    // vector<vector<int>> mine2 {
    //     {1,0,9,3,6,7},
    //     {1,3,7,9,0,0},
    //     {4,2,0,6,1,8},
    //     {2,8,1,4,2,3},
    //     {0,5,0,5,6,4},
    //     {7,4,7,8,1,5}  
    // };

    // gold_mine(mine2, 3);

    // int arr[] = {2,5,3,1,6};
    // int n = sizeof(arr) / sizeof(int);
    // int tar = 9;
    // target_sum(arr, n, tar);

    vector<int> arr = {2,3,5,6};
    // cout << cc_perm_count(arr, 7) << endl;
    cout << cc_comb_count(arr, 7) << endl;
}