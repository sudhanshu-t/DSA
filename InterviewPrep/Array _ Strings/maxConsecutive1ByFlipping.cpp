#include<iostream>
#include<vector>
using namespace std;

// Function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// This is a functional problem. You have to complete this function.
// It takes as input a binary array. It should return the maximum number
// of consecutive 1s in this array if you can flip at most one 0.
int findMaxConsecutiveOnes(vector<int> &nums) {
    int i = -1, j = 0;

    int count = 0;
    int mymax = 0;
    while(j < nums.size()){
        if(nums[j] != 1){
            count++;

            if(count > 1){
                mymax = max(mymax, j - i - 1);
            }

            while(count > 1){
                i++;
                if(nums[i] == 0){
                    count--;
                }
            }
        }
        j++;
    }

    mymax = max(mymax, j - i - 1);

    return mymax;
}

int main(int argc, char** argv){
    int N; cin>>N;
    vector<int> arr1(N);
    // Input for array1 elements.
    for (int i = 0; i < arr1.size(); i++) {
        cin>>arr1[i];
    }
    int result = findMaxConsecutiveOnes(arr1);
    cout<<result;
}