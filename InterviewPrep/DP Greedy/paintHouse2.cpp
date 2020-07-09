#include<iostream>
#include<vector>
#include <climits>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2D array
// It should return the required output
int minCostII(vector<vector<int>>& costs) {
    //Write your code here
    
    int minCost = INT_MAX;
    
    vector<int> res (costs[0].size());
    
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int smallestIdx = 0, secondSmallestIdx = 0;
    for(int i = 0; i < costs[0].size(); i++){
        res[i] = costs[0][i];
        
        if(res[i] < smallest){
            smallest = res[i];
            smallestIdx = i;
        }
    }

    // cout << smallest << " " << secondSmallest << endl;

    
    // Second Smallest
    for(int i = 0; i < costs[0].size(); i++){
        if(res[i] > smallest && res[i] < secondSmallest){
            secondSmallest = res[i];
            secondSmallestIdx = i;
        }
    }
    
    cout << "s " << smallest << " - ss " << secondSmallest << endl;

    if(costs[0].size() == 1){
        smallest = secondSmallest = costs[0][0];
        smallestIdx = secondSmallestIdx = 0;
    }

    if(costs.size() == 1){
        return smallest;
    }
    
//  smallest = smallestIdx;
//  secondSmallest = secondSmallestIdx;
    
    for(int i = 1; i < costs.size(); i++){
        for(int k = 0; k < costs[0].size(); k++){
            if(k == smallestIdx){
                res[k] = costs[i][k] + secondSmallest;
            } else {
                res[k] = costs[i][k] + smallest;
            }
            
        //  cout << "Res " << res[k] << " ";
            if(i == costs.size() - 1){
                minCost = min(minCost, res[k]);
            }
        }
        
        smallest = INT_MAX;
        secondSmallest = INT_MAX;
        
        for(int k = 0; k < costs[0].size(); k++){
            if(res[k] < smallest){
                smallest = res[k];
                smallestIdx = k;
            }
        }
    
        
    // Second Smallest
        for(int k = 0; k < costs[0].size(); k++){
            if(res[k] > smallest && res[k] < secondSmallest){
                secondSmallest = res[k];
                secondSmallestIdx = k;
            }
        }
        
    //  cout << smallest << " " << secondSmallest << endl;
    //  cout << smallestIdx << " " << secondSmallestIdx << endl;
        cout << "s " << smallest << " - ss " << secondSmallest << endl;

    }

    return minCost;
// cout << smallest << " " << secondSmallest << endl;
}

int main(int argc,char** argv) {
    int n ,k;
    cin>>n>>k;
    vector<vector<int>> costs(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>costs[i][j];
        }
    }
    cout<<minCostII(costs)<<endl;
}