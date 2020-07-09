#include <iostream>
#include <vector>
using namespace std;

int maximumGap(const vector<int> &A) {
    if(A.size() == 1){
        return 0;
    }
    
    vector<int> maxFromRight (A.size());
    vector<int> minFromLeft (A.size());
    
    for(int i = 0; i < A.size(); i++){
        if(i == 0){
            minFromLeft[i] = A[i];
        } else {
            minFromLeft[i] = min(A[i], minFromLeft[i-1]);
        }
    }
    
    for(int i = A.size() - 1; i >= 0; i--){
        if(i == A.size() - 1){
            maxFromRight[i] = A[i];
        } else {
            maxFromRight[i] = max(A[i], maxFromRight[i+1]);
        }
    }
    
    int i = 0, j = 0, count = 0;
    
    while(j < A.size()){
        if(minFromLeft[i] <= maxFromRight[j]){
            count = max(count, j - i);
            j++;
        } else {
            i++;
        }
    }
    
    return count;
}

int main(){
    vector<int> A = {5,4,3,2,1,9};
    cout << maximumGap(A) << endl;
}