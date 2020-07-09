#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res (nums.size());
    int pro = 1;

    for(int i = 0; i < nums.size(); i++){
        pro *= nums[i];
    }

    for(int i = 0; i < res.size(); i++){
        res[i] = pro / nums[i];
    }

    return res;
}

//Don't make any changes here.
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> Input(n);
    for(int i=0;i<n;i++){
        cin>>Input[i];
    }
    vector<int> ans = productExceptSelf(Input);
    for (int i : ans) {
        cout<<i<<" ";
    }

}