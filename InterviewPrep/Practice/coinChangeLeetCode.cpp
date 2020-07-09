#include <bits/stdc++.h>
using namespace std;

// int ans = INT_MAX;
    
// void getAns(vector<int>& coins, int idx, int tar, int count, string psf){
//     if(tar == 0){
//         cout << psf << endl;
//         ans = min(ans, count);
//         return;
//     }

//     for(int i = idx; i < coins.size(); i++){
//         if(coins[i] <= tar){
//             getAns(coins, i, tar - coins[i], count+1, psf + to_string(coins[i]) + " ");
//         }
//     }
// }

int coinChange(vector<int>& coins, int amount) {
    // getAns(coins, 0, amount, 0, "");
    // return (ans == INT_MAX) ? -1 : ans;
    if(coins.size() == 0){
        return -1;
    }

    vector<int> minLength (amount+1, INT_MAX);
    vector<int> ways (amount+1, 0);

    ways[0] = 1;
    minLength[0] = 0;

    for(int i = 0; i < coins.size(); i++){
        for(int j = 0; j < ways.size(); j++){
            if(coins[i] <= j){
                if(ways[j-coins[i]] > 0){
                    ways[j] += ways[j-coins[i]];
                    minLength[j] = min(minLength[j], minLength[j-coins[i]]+1);
                }
            }
        }
    }

    // for(int i = 0; i < ways.size(); i++){
    //     cout << minLength[i] << endl;
    // }

    int ans = minLength[minLength.size() - 1];
    if(ans != INT_MAX){
        return ans;
    } else {
        return -1;
    }
}

int main(){
    vector<int> coins = {19,28,176,112,30,260,491,128,70,137,253};
    cout << coinChange(coins, 8539) << endl;
}