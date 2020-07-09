#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int eggDrop(vector<vector<int>>& qb, int e, int f){
    if(f == 1 || e == 1 || f == 0){
        qb[e][f] = f;
        return f;
    }
    
    if(qb[e][f] != -1){
        return qb[e][f];
    }
    
    int globalMin = INT_MAX;
    for(int k = 1; k <= f; k++){
        int breaks = eggDrop(qb, e-1, k-1);
        int saved = eggDrop(qb, e, f - k);
        
        int myMax = max(breaks, saved);

        globalMin = min(globalMin, myMax);
    }
    
    qb[e][f] = globalMin + 1;
    return globalMin + 1;
}

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int e, f;
        cin >> e >> f;
        
        vector<vector<int>> qb (e + 1, vector<int> (f + 1, -1));
        cout << eggDrop(qb, e, f) << endl;
    }
    
    return 0;
}