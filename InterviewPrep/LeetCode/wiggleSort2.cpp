#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int>& nums) {
    if(nums.size() < 2){
        return;
    }
    
    if(nums.size() == 2){
        sort(nums.begin(), nums.end());
        return;
    }
    
    int prev = 0; int curr = 1;
    bool inc = true;
    
    while(prev < nums.size() - 1){
        if(inc == false){
            if(nums[prev] > nums[curr]){
                // sahi hai
            } else if (nums[prev] < nums[curr]){
                swap(nums[prev], nums[curr]);
            } else {
                while(nums[prev] <= nums[curr] && curr < nums.size()){
                    curr++;
                }

                if(curr == nums.size()){
                    curr = prev + 1;

                    while(nums[curr] <= nums[prev] && curr < nums.size()){
                        curr++;
                    }

                    if(curr < nums.size()) swap(nums[prev], nums[curr]);
                } else {
                    swap(nums[prev + 1], nums[curr]);
                }
            }
        } else {
            if(nums[prev] < nums[curr]){
                // sahi hai
            } else if (nums[prev] > nums[curr]){
                swap(nums[prev], nums[curr]);
            } else {
                while(nums[prev] >= nums[curr] && curr < nums.size()){
                    curr++;
                }

                if(curr == nums.size()){
                    curr = prev + 1;

                    while(nums[curr] >= nums[prev] && curr < nums.size()){
                        curr++;
                    }

                    if(curr < nums.size()) swap(nums[prev], nums[curr]);
                } else {
                    swap(nums[prev + 1], nums[curr]);
                }
            }
        }
        
        inc = !inc;           
        prev++;
        curr = prev + 1;

        // for(int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }

        // cout << endl;
    }

    bool correct = true;

    bool checkFlag = true;
    for(int i = 0; i < nums.size() - 1; i++){
        if(checkFlag == true){
            if(nums[i] < nums[i + 1]){
                checkFlag = false;
                continue;
            } else {
                correct = false;
                break;
            }
        } else {
            if(nums[i] > nums[i + 1]){
                checkFlag = true;
                continue;
            } else {
                correct = false;
                break;
            }
        }
    }

    if(correct){
        return;
    } else {
        // for(int i = 0; i < nums.size() / 2; i++){
        //     swap(nums[i], nums[nums.size() - i - 1]);
        // }

        reverse(nums.begin(), nums.end());

        wiggleSort(nums);
    }
}

int main(int argc, char** argv){
    vector<int> arr = {4,3,2,2};

    wiggleSort(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}