#include<iostream>
#include<vector>
using namespace std;

// function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// This is a functional problem. You have to complete this function.
// It takes as input an integer array. It should return
// the required array.
vector<int> sortedSquares(vector<int> &A) {
    for(int i = 0; i < A.size(); i++){
        A[i] = A[i]*A[i];
    }

    int left = 0;
    int right = A.size() - 1;

    int idx = A.size() - 1;
    vector<int> res (A.size());

    // for(int i = 0; i < A.size(); i++){
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    
    while(left <= right){
        if(A[left] >= A[right]){
            res[idx] = A[left];
            left++;
        } else {
            res[idx] = A[right];
            right--;
        }
        idx--;
    }

    return res;
}

int main(int argc, char** argv){
    int length;
    cin>>length;
    vector<int> arr(length);

    // Input for elements of array.
    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }

    vector<int> result = sortedSquares(arr);
    display(result);

}