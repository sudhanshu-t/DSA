#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

// Function to display a matrix.
void display(vector<vector<int> >&mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

// This is a functional problem. You have to complete this function.
// It takes as input a matrix and K.
// It should return the Kth smallest element from the matrix.
int findKthSmallest(vector<vector<int> >& nums, int k) {
    // write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            pq.push(nums[i][j]);
        }
    }

    int temp = 0;
    for(int i = 0; i < k; i++){
        temp = pq.top();
        pq.pop();
    }

    return temp;
}

int main(int argc,char** argv){
    
    // Input for length of first array.
        int N;
        cin>>N;

        vector<vector<int> > mat(N,vector<int>(N) );

        // Input for matrix elements.
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                cin>>mat[i][j];
            }
        }

        int K;
        cin>>K;
        int result = findKthSmallest(mat, K);

        cout<<result<<endl;
}