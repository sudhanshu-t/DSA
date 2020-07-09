#include<climits>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and an integer 
// It should return an integer value.

int threeSumClosest(vector<int>& nums, int target) {
    //Write your code here
    int closest = INT_MAX;
    int sum = 0;
    
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        int left = i+1;
        int right = nums.size() - 1;

        int remtar = target - nums[i];
        while(left < right){
            if(nums[left] + nums[right] == remtar){
                return target;
            } else {
                int diff = abs(remtar - nums[left] - nums[right]);

                if(diff < closest){
                    closest = diff;
                    sum = nums[i] + nums[left] + nums[right];
                }

                if(nums[left] + nums[right] > remtar){
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    
    return sum;
}

int main(int argc, char** argv){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int res=threeSumClosest(nums,k);
    cout<<res;

}