#include<iostream>
#include<vector>
#include<string>
using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input a length and a 2D array of update operations.
// It should return the modified array.
vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
    // write your code here. 
    vector<int> presum (length, 0);
    vector<int> arr (length, 0);
    
    for(int i = 0; i < updates.size(); i++){
        arr[updates[i][0]] += updates[i][2];
        arr[updates[i][1] + 1] += -updates[i][2];
    }

    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        presum[i] = sum;
    }

    return presum;
}

// function to display an array.
void display(vector<int> & arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc,char** argv){
    
    // Input for length of first array.
    int length ;
    cin>>length;

    int K;
    cin>>K;

    vector<vector<int> > updates(K,vector<int>(3));

    for (int i = 0; i < updates.size(); i++) {
        for (int j = 0; j < updates[i].size(); j++) {
            cin>>updates[i][j];
        }
    }

    vector<int> res= getModifiedArray(length, updates);
    display(res);
}