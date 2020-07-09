#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;

    if(nums.size() == 0){
        vector<int> temp;
        res.push_back(temp);
        
        return res;
    }
    
    if(nums.size() == 1){
        res.push_back(nums);
        return res;
    }

    unordered_set<int> set;

    for(int i = 0; i < nums.size(); i++){
        if(set.find(nums[i]) == set.end()){
            set.insert(nums[i]);

            vector<int> arr;
            
            for(int j = 0; j < nums.size(); j++){
                if(i != j) arr.push_back(nums[j]);
            }

            // for(int j = 0; j < arr.size(); j++){
                // cout << arr[j] << " ";
            // }
            // cout << endl;

            vector<vector<int>> rres = permuteUnique(arr);

            // for(int x = 0; x < rres.size(); x++){
            //     for(int y = 0; y < rres[x].size(); y++){
            //         cout << rres[x][y] << ", ";
            //     }
            //     cout << endl;
            // }

            for(int j = 0; j < rres.size(); j++){
                rres[j].push_back(nums[i]);
                res.push_back(rres[j]);
            }
        }
    }
    
    return res;
}

int main(){
    vector<int> nums = {1,2,2,1,3};
    vector<vector<int>> res = permuteUnique(nums);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}