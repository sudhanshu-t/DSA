#include <bits/stdc++.h>
using namespace std;

int ways = 0;

void ans(int n, int psf, vector<int> count, string path){
    if(psf == n){
        // cout << path << endl;
        ways++;
        return;
    }

    for(int i = 0; i < count.size(); i++){
        if(count[i] != 2){
            vector<int> temp(count.size());
            temp[i] = count[i] + 1;
            ans(n, psf+1, temp, path + "c" + to_string(i+1) + " ");
        }
    }
}

int numWays(int n, int k) {
    int lastInc = 0, num = 1;

    if(n == 0 || k == 0){
        return 0;
    }

    if(n == 1){
        return k;
    }

    for(int i = 0; i < n; i++){
        int safe = num;
        num = (k-1)*num + num - lastInc;
        lastInc = safe - lastInc;
    }
    
    return k*num;
    // vector<int> count (k);

    // ans(n, 0, count, "");

    // return ways;
}

int main(){
    cout << numWays(4,3) << endl;
}