#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int minDiff = INT_MAX, minS;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        
        int tar = target - nums[i];
        
        while(j < k){
            int diff = abs(nums[j] + nums[k] - tar);
            
            if(diff < minDiff){
                minS = nums[i] + nums[j] + nums[k];
                minDiff = diff;

                // cout << minS << " with diff = " << minDiff << endl;
            }

            if(nums[j] + nums[k] < tar){
                j++;
            } else if (nums[j] + nums[k] > tar){
                k--;
            } else {
                break;
            }
        }
    }
    
    return minS;
}

int main(){
    vector<int> nums = {-1,2,1,-4};
    cout << threeSumClosest(nums, 1) << endl;
}