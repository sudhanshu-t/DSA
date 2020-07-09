#include <iostream>
#include <vector>
using namespace std;

// int res = 0;
// void comb(vector<int>& nums, int target){
//     if(target == 0){
//         res++;
//         return;
//     }
    
//     for(int i = 0; i < nums.size(); i++){
//         if(nums[i] <= target){
//             comb(nums, target - nums[i]);
//         }
//     }
// }

// int combinationSum4(vector<int>& nums, int target) {
//     comb(nums, target);
//     return res;
// }
int combinationSum4(vector<int>& nums, int target) {
    vector<vector<int>> dp (nums.size(), vector<int> (target + 1));

    for(int j = 0; j < dp[0].size(); j++){
        for(int i = 0; i < dp.size(); i++){
            if(j == 0){
                dp[i][j] == 0;
                continue;
            }
            
            if(i+1 == j){
                dp[i][j] = 1;
                continue;
            }
            
            if(i+1 > j){
                dp[i][j] = 0;
                continue;
            }
            
            int sum = 0;
            for(int k = i; k < dp.size(); k++){
                sum += dp[k][j-1];
            }
            
            dp[i][j] = sum;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < dp.size(); i++){
        ans += dp[i][dp[0].size() - 1];
    }

    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return ans;
}
int main(){
    vector<int> nums = {1,2,3};
    cout << combinationSum4(nums, 4) << endl;
}