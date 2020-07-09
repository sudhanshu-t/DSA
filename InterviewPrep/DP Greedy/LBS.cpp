#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> DIS(const vector<int>& arr){
    vector<int> strg (arr.size());
    
    strg[strg.size() - 1] = 1;
    int globalMax = INT_MIN;
    for(int i = strg.size() - 2; i >= 0; i--){
        int myMax = INT_MIN;
        for(int j = i+1; j < strg.size(); j++){
            if(arr[j] < arr[i]){
                myMax = max(myMax, strg[j]);
            }
        }
        
        if(myMax != INT_MIN){
            strg[i] = myMax + 1;
        } else {
            strg[i] = 1;
        }
        
        globalMax = max(globalMax, strg[i]);
    }
    
    return strg;
}

vector<int> LIS(const vector<int>& arr){
    vector<int> strg (arr.size());
    
    int globalMax = INT_MIN;
    strg[0] = 1;
    for(int i = 1; i < strg.size(); i++){
        int myMax = INT_MIN;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                myMax = max(myMax, strg[j]);
            }
        }
        
        if(myMax != INT_MIN){
            strg[i] = myMax + 1;
        } else {
            strg[i] = 1;
        }
        
        globalMax = max(globalMax, strg[i]);
    }
    
    return strg;
}

int longestSubsequenceLength(const vector<int> &A) {
    vector<int> lis = LIS(A);
    vector<int> dis = DIS(A);
    
    int myMax = INT_MIN;
    for(int i = 0; i < A.size(); i++){
        int pot = lis[i] + dis[i];
        
        myMax = max(myMax, pot);
    }
    
    return myMax - 1;
}

int main(){
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << longestSubsequenceLength(arr) << endl;
}