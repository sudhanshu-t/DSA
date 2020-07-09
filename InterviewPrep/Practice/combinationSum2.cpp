#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

void combSum(vector<int>& arr, int target, int idx, vector<vector<int>>& res, vector<int>& temp){
    if(target == 0){
        res.push_back(temp);
        return;
    }
    
    unordered_set<int> set;
    
    for(int i = idx; i < arr.size(); i++){
        if(set.find(arr[i]) == set.end() && arr[i] <= target){
            set.insert(arr[i]);
            
            temp.push_back(arr[i]);
            combSum(arr, target - arr[i], i+1, res, temp);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;

    sort(candidates.begin(), candidates.end());
    
    combSum(candidates, target, 0, res, temp);

    return res;
}

int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    vector<vector<int>> res = combinationSum(nums, 8);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}