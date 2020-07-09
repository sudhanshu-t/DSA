#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array
// Print required output
void zerosumarr(vector<long> arr){
    //Write your code here
    unordered_map<long, long> fmap;

    long int sum = 0;
    int count = 0;
    fmap[0] = 1;

    for(int val : arr){
        sum += val;
        fmap[sum]++;

        count += fmap[sum] - 1;
    }

    cout << count << endl;
}

//Don't make any changes here.
int main(int argc, char** argv){
    int size; 
    cin>>size;
    vector<long> a;
    for (int z = 0; z < size; z++) {
        long val;
        cin>>val;
        a.push_back(val);
    }
    zerosumarr(a);
}