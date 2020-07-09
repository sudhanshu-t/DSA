#include <iostream>
#include <vector>
using namespace std;

void combSum(vector<int>& arr, int target, int idx, vector<vector<int>>& res, vector<int>& temp){
    if(target == 0){
        res.push_back(temp);
        return;
    }
    
    for(int i = idx; i < arr.size(); i++){
        if(arr[i] <= target){
            temp.push_back(arr[i]);
            combSum(arr, target - arr[i], i, res, temp);
            temp.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    
    combSum(candidates, target, 0, res, temp);

    return res;
}

int main(){
    vector<int> nums = {2,3,6,7};
    vector<vector<int>> res = combinationSum(nums, 10);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}