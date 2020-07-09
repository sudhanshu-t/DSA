#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(const vector<int> &A) {
    vector<unordered_map<int, int>> strg (A.size());
    
    int myMax = 1;
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            int diff = A[i] - A[j];
            if(strg[j].find(diff) != strg[j].end()){
                strg[i][diff] = strg[j][diff] + 1;
            } else {
                strg[i][diff] = 2;
            }

            myMax = max(myMax, strg[i][diff]);
        }
    }

    return myMax;
}

int main(){
    vector<int> arr = {1,9,4,7,13,9,10, 1,1,1,1};
    int maxAP = solve(arr);
    cout << maxAP << endl;
}