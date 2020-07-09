#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    
    if(nums.size() < 3){
        return res;
    }
    
    unordered_set<string> set;

    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size() - 2; i++){
        int j = i+1;
        int k = nums.size() - 1;
        
        int tar = -(nums[i]);
        
        while(j < k){
            if(nums[j] + nums[k] > tar){
                k--;
            } else if (nums[j] + nums[k] < tar){
                j++;
            } else {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);

                string s = to_string(temp[0]) + to_string(temp[1]) + to_string(temp[2]);

                // cout << tar << " " << s << endl;
                if(set.find(s) == set.end()){
                    res.push_back(temp);
                    set.insert(s);
                }

                j++;
                k--;
                continue;
            }
        }
    }
    
    return res;
}

int main(){
    vector<int> arr = {-2,0,1,0,0,0,1};
    vector<vector<int>> res = threeSum(arr);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}