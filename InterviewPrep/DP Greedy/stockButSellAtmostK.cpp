#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written
// This function takes as input an array and 2 integers
// It should return the required output


int maxProfit(vector<int> &prices,int n,int k) {
    //Write your code here
    
    vector<vector<int>> strg (k + 1, vector<int> (n));
for(int i = 1; i <= k; i++){
    for(int j = 0; j < n; j++){
        if(j >= 1){
            int maxV = strg[i][j-1]; 
            for(int c = j-1; c >= 0; c--){
                maxV = max(maxV, strg[i-1][c] + prices[j] - prices[c]);
            }
            
            strg[i][j] = maxV;
        }   
    }
}

return strg[k][n-1];
}

int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++){
        cin>>prices[i];
    }
    int k;
    cin>>k;
    cout<<maxProfit(prices,n,k);
}

