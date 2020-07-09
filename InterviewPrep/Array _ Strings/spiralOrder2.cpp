#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> res (A, vector<int> (A));
    
    int maxCount = A * A, count = 1;
    int maxR = A - 1;
    int minR = 0;
    int maxC = A - 1;
    int minC = 0;

    while(count <= maxCount && minC <= maxC && minR <= maxR){
        // upper wall
        for(int j = minC; j <= maxC && minC <= maxC && minR <= maxR; j++){
            res[minR][j] = count;
            // res.push_back(res[minR][j]);
            // cout << res[minR][j] << " ";
            count++;
        }

        minR++;

        // right wall
        for(int i = minR; i <= maxR && minC <= maxC && minR <= maxR; i++){
            res[i][maxC] = count;
            // res.push_back(res[i][maxC]);
            // cout << res[i][maxC] << " ";

            count++;
        }

        maxC--;

        // bottom wall
        for(int j = maxC; j >= minC && minC <= maxC && minR <= maxR; j--){
            res[maxR][j] = count;
            // res.push_back(res[maxR][j]);
            // cout << res[maxR][j] << " ";

            count++;
        }

        maxR--;
        
        // left wall
        for(int i = maxR; i >= minR && minC <= maxC && minR <= maxR; i--){
            res[i][minC] = count;
            // res.push_back(res[i][minC]);
            // cout << res[i][minC] << " ";

            count++;
        }

        minC++;
    }

    return res;
}

int main(int argc, char** argv){
    vector<vector<int>> res = generateMatrix(5);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res.size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}