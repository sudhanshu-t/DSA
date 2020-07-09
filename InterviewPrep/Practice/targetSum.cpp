#include <bits/stdc++.h>
using namespace std;

int ways = 0;
int countWays(vector<int>& nums, int target, int ssf, int idx, string psf, vector<vector<int>>& dp){
    if(idx == nums.size()){
        // cout << "Hi" << endl;
        if(target == ssf){
            // ways++;
            // cout << psf << endl;
            return 1;
        }
        return 0;
    }

    if(dp[idx][ssf+1000] != -1){
        return dp[idx][ssf+1000];
    }
    
    int w1 = countWays(nums, target, ssf + nums[idx], idx+1, psf + "+" + to_string(nums[idx]) + " ", dp);
    int w2 = countWays(nums, target, ssf - nums[idx], idx+1, psf + "-" + to_string(nums[idx]) + " ", dp);

    dp[idx][ssf+1000] = w1 + w2;

    // if(idx == 0){
    //     cout << dp[idx][ssf+1000] << endl;
    // }
    return dp[idx][ssf+1000];
}

int findTargetSumWays(vector<int>& nums, int S) {
    vector<vector<int>> dp (20, vector<int> (2001, -1));
    int ans = countWays(nums, S, 0, 0, "", dp);
    return ans;
}

int main(){
    vector<int> nums = {29,6,7,36,30,28,35,48,20,44,40,2,31,25,6,41,33,4,35,38};
    cout << findTargetSumWays(nums, 35) << endl;
}