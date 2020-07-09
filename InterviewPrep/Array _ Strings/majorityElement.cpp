#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    //Write your code here
    int pot = nums[0];

    int count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != pot){
            count--;

            if(count == 0){
                count = 1;
                pot = nums[i];
            }
        } else {
            count++;
        }
    }

    count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == pot){
            count++;
        }
    }

    if(count > nums.size() / 2){
        return pot;
    } else {
        return -1;
    }
}


int main(int argc,char**argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   
    int res=majorityElement(v);
    cout<<res<<endl;
}