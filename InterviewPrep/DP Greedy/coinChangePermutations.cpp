#include<iostream>
#include<vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<int> strg (target + 1);

    strg[0] = 1;
    for(int i = 1; i <= target; i++){
        int ways = 0;
        for(int c = 0; c < nums.size(); c++){
            if(i >= nums[c]){
                ways += strg[i - nums[c]];
            }
        }
        strg[i] = ways;
    }

    return strg[target];
}

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    int target;
    cin>>target;
    cout<<combinationSum4(nums,target)<<endl;
}