#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> strg (n + 1, vector<int> (k + 1));

    for(int i = 1; i < strg.size(); i++){
        for(int j = 1; j < strg[0].size(); j++){
            if(j == 1){
                strg[i][j] = 1;
                continue;
            }
            
            strg[i][j] = j * strg[i-1][j] + strg[i-1][j-1];
        }
    }

    cout << strg[strg.size() - 1][strg[0].size() - 1];
    return 0;
}