#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array and 3 integers
// It should return an integeral array

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    for(int i = 0; i < nums.size(); i++){
        nums[i] = a*nums[i]*nums[i] + b*nums[i] + c;
    }

    int left = 0;
    int right = nums.size() - 1;
    vector<int> res (nums.size());

    int i = nums.size() - 1;

    while(left <= right){
        if(nums[left] < nums[right]){
            res[i] = nums[right];
            right--;
        } else {
            res[i] = nums[left];
            left++;
        }

        i--;
    }

    return res;
}


int main(int argc,char** argv){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> res;
        res=sortTransformedArray(nums, a, b, c);
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
}