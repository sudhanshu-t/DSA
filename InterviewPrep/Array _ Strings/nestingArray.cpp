#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int arrayNesting(vector<int> &nums) {
    vector<bool> visited (nums.size());
    
    int mymax = 0;
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i];
        visited[i] = true;

        int count = 1;
        while(visited[x] != true)
        {
            count++;
            visited[x] = true;
            x = nums[x];
        }

        mymax = max(mymax, count);   
    }

    return mymax;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        cin>>arr[i];
    }
    cout<<arrayNesting(arr);
}