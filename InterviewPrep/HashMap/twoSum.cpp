#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
vector<int> twoSum(vector<int> nums, int target) {
    //Write your code here
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++){
        map[nums[i]] = i;
    }

    // for(auto itr : map){
    //     cout << itr.first << " " << itr.second << endl;
    // }

    vector<int> res (2, -1);
    for(int i = 0; i < nums.size(); i++)
    {
        if(map.find(target - nums[i]) != map.end()){
            // cout << nums[i] << " " << nums[map[target-nums[i]]] << endl;
            res[0] = i;
            res[1] = map[target - nums[i]];
            return res;
        }
    }
}

//Don't make any changes here.
int main(int argc, char** argv){
    vector<int> nums;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int val;
        cin>>val;
        nums.push_back(val);
    }
    int target;
    cin>>target;
    vector<int> res = twoSum(nums, target);
    cout<<"[";
    for(int i=0; i<res.size(); i++){
        cout<<res[i];
        if(i != res.size() - 1){
            cout<<", ";
        }
    }
    cout<<"]";
}