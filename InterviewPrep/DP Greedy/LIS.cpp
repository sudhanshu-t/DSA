#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return nums.size();
        }
        
        vector<int> strg (nums.size(), 0);
        strg[0] = 1;
        
        int globalMax = strg[0];
        for(int i = 1; i < strg.size(); i++){
            int myMax = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    myMax = max(strg[j], myMax);
                }
            }
            
            if(myMax == 0){
                strg[i] = 1;
            } else {
                strg[i] = myMax + 1;
            }
            
            globalMax = max(globalMax, strg[i]);
            
            // cout << nums[i] << " " << globalMax << " " << myMax << endl;
        }
        
        return globalMax;
    }
};