#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array
// It should return a boolean value.
bool splitArray(vector<int> & nums) { 
    unordered_set<int> set;
    vector<int> presum (nums.size());
    
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        presum[i] = sum;
    }
    
    for(int j = 3; j < nums.size(); j++){
        for(int i = 1; i <= j-2; i++){
            if(presum[i-1] == presum[j-1] - presum[i]){
                set.insert(presum[i-1]);
            }
        }

        for(int k = j+2; k < nums.size(); k++){
            if(presum[nums.size()-1] - presum[k] == presum[k-1] - presum[j]){
                if(set.find(presum[nums.size() - 1] - presum[k]) != set.end()){
                    return true;
                }
            }
        }

        set.clear();
    }
    
    return false;
}
int main(int argc,char** argv){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bool res=splitArray(nums);
    if(res==true){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}