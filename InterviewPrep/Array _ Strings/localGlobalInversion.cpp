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

bool isIdealPermutation(vector<int> &A) {
    // This method only tells if there are global inversions which aren't local ones, not the count of local and global inversions. 
    for(int i = 0; i < A.size(); i++){
        if(abs(A[i] - i) > 1){
            return false;
        }
    }
    
    return true;
}

int main(int argc, char** argv){
    int N;
    cin>>N;
    vector<int> arr(N);

    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }

    if (isIdealPermutation(arr)) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }

}