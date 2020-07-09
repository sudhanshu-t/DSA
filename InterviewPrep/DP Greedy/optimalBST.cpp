#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int optimalBST(vector<int>& arr, vector<int>& freq){
    vector<int> freqSum (freq.size() + 1, 0);

    int sum = 0;
    for(int i = 0; i < freq.size(); i++){
        sum += freq[i];
        freqSum[i + 1] = sum;
    }

    vector<vector<int>> strg(arr.size() + 1, vector<int> (arr.size() + 1, 0));

    for(int x = 1; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            int myMin = INT_MAX;
            for(int k = i; k < j; k++){
                myMin = min(myMin, strg[i][k] + strg[k+1][j]);
            }

            strg[i][j] = myMin + freqSum[j] - freqSum[i];
        }
    }

    return strg[0][strg.size() - 1];
}

int main(int argc, char** argv){
    vector<int> keys = {10, 12, 20}, freq = {34, 8, 50};

    cout << optimalBST(keys, freq) << endl;
}