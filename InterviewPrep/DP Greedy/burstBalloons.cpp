#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array 
// It should return the required output

int maxCoins(vector<int> &nums) {
    //Write your code here
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> strg (nums.size(), vector<int> (nums.size()));
    
    for(int x = 2; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg[0].size(); i++, j++){
        int myMax = INT_MIN;
        for(int k = i+1; k < j; k++){
            myMax = max(myMax, strg[i][k] + strg[k][j] + nums[i] * nums[k] * nums[j]);
        }
        
        strg[i][j] = myMax;
        }
    }

    for (auto &&i : strg){
        for (auto &&j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    
    
    return strg[0][strg.size() - 1];
}

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }
    cout<<maxCoins(nums)<<endl;
}