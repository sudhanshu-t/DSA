#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    vector<int> l2r (A.size());
    vector<int> r2l (A.size());
    
    int maxPro = 0;
    int minSoFar = A[0];
    for(int i = 1; i < A.size(); i++){
        if(A[i] < minSoFar){
            minSoFar = A[i];
        } else {
            maxPro = max(maxPro, A[i] - minSoFar);
        }
        
        l2r[i] = maxPro;
    }
    
    int maxSoFar = A[A.size() - 1];
    maxPro = 0;
    for(int i = A.size() - 2; i >= 0; i--){
        if(A[i] > maxSoFar){
            maxSoFar = A[i];
        } else {
            maxPro = max(maxPro, maxSoFar - A[i]);
        }
        
        r2l[i] = maxPro;
    }
    
    maxPro = 0;
    for(int i = 0; i < A.size(); i++){
        maxPro = max(maxPro, l2r[i] + r2l[i]);
    }
    
    return maxPro;
}

int main(){
    vector<int> arr = {8,8,8,8,8};
    cout << maxProfit(arr) << endl;
}