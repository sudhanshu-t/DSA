#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2D array
// It should return the required output
int minCost(vector<vector<int>>& costs) {
    //Write your code here

    int r = costs[0][0], g = costs[0][1], b = costs[0][2];
    
    for(int i = 1; i < costs.size(); i++){
        int safeR = min(g, b) + costs[i][0];
        int safeG = min(r, b) + costs[i][1];
        int safeB = min(g, r) + costs[i][2];
        
        r = safeR;
        g = safeG;
        b = safeB;
    }
    
//   cout << r << " " << b << " " << g << endl;
    
    return min(r, min(b, g));
}

int main(int argc,char** argv) {
    int n ;
    cin>>n;
    vector<vector<int>> costs(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>costs[i][j];
        }
    }
    cout<<minCost(costs)<<endl;
}