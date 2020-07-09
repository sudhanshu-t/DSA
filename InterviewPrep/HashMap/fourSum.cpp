#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input the head of the linked list.
// It should return the head of the modified list.

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
// write your code here    
    vector<vector<int>> ans;
    if(nums.size() < 4){
        return ans;
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            int ij = nums[i] + nums[j];
            int l = j + 1;
            int r = nums.size() - 1;
            while(l < r){
                if(ij + nums[l] + nums[r] == target){
                    vector<int> temp (4);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[l];
                    temp[3] = nums[r];

                    ans.push_back(temp);

                    while(nums[l+1] == nums[l]){
                        l++;
                    }
                    l++;
                } else if(ij + nums[l] + nums[r] < target){
                    while(nums[l+1] == nums[l]){
                        l++;
                    }
                    l++;
                } else {
                    while(nums[r-1] == nums[r]){
                        r--;
                    }
                    r--;
                }
            }

            while(nums[j+1] == nums[j]){
                j++;
            }
        }

        while(nums[i+1] == nums[i]){
            i++;
        }
    }

    // for(int i = 0; i < ans.size(); i++){
    //     for(int j = 0; j < ans[i].size(); j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return ans;
}

// -----------------------------------------------------

int main(int args, char **argv)
{
    int n, target;
    cin >> target >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> list = fourSum(nums, target);

    for (int i = 0; i < list.size(); i++)
    {
        for (int j = 0; j < list[i].size(); j++)
        {
            if (j == list[i].size() - 1)
                cout << list[i][j];
            else
                cout << list[i][j] << " ";
        }
        cout << endl;   
    }
}