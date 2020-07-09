#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
int countSubArrays(vector<int> a, int n) {
    unordered_map<int, int> map;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0){
            a[i] = -1;
        }
    }

    int presum = 0, count = 0;
    map[0] = 1;
    for(int i = 0; i < a.size(); i++){
        presum += a[i];

        count += map[presum];
        map[presum]++;
    }

    return count;    
}

//Don't make any changes here.
int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> a;
    for (int z = 0; z < n; z++) {
        int val;
        cin>>val;
        a.push_back(val);
    }
    cout<<countSubArrays(a, n);
}