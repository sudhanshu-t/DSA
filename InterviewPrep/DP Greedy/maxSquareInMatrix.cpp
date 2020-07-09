#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxSquare(vector<vector<int>>& matrix){
    vector<vector<int>> strg (matrix.size(), vector<int> (matrix[0].size(), 0));

    int myMax = INT_MIN;

    for(int i = strg.size() - 1; i >= 0; i--){
        for(int j = strg[0].size() - 1; j >= 0; j--){
            if(i == strg.size() - 1 || j == strg[0].size() - 1){
                strg[i][j] = matrix[i][j];
                myMax = max(myMax, strg[i][j]);
                continue;
            }

            if(matrix[i][j] == 0){
                strg[i][j] = 0;
                continue;
            }

            strg[i][j] = min(strg[i+1][j], min(strg[i+1][j+1], strg[i][j+1])) + 1;
            myMax = max(myMax, strg[i][j]);
        }
    }

    return myMax;
}

int main(int argc, char** argv){
    vector<vector<int>> matrix = {
        {1,0,1,0,1,1,1,0},
        {0,1,1,1,1,0,1,1},
        {0,1,1,1,0,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,0,1,1},
    };

    cout << maxSquare(matrix) << endl;
}