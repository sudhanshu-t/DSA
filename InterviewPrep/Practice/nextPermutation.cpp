#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    bool found = false;
    int dip;
    for(int i = nums.size() - 1; i > 0; i--){
        if(nums[i-1] < nums[i]){
            dip = i-1;
            found = true;
            break;
        }
    }
    
    if(!found){
        for(int i = 0; i < nums.size() / 2; i++){
            int temp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = temp;
        }
        
        return;
    }

    for(int i = nums.size() - 1; i > dip; i--){
        if(nums[i] > nums[dip]){
            int temp = nums[i];
            nums[i] = nums[dip];
            nums[dip] = temp;
            
            for(int j = 0; j < (nums.size() - dip - 1) / 2; j++){
                int temp = nums[dip + j + 1];
                nums[dip + j + 1]  = nums[nums.size() - j - 1];
                nums[nums.size() - j - 1] = temp;
            }

            break;
        }
    }
}

int main(){
    vector<int> nums = {2,2,0,4,3,1};
    nextPermutation(nums);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
    cout << endl;
}