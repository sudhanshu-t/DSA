#include<iostream>
#include<string>
#include<vector>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an N.
// It should return an integer value.

int solve(int N) {
    //Write your code here
    int h = 0;
    while((1 << h) < N) h++;
    return h;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<solve(n)<<endl;
}