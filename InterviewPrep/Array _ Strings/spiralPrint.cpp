#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> res;
    
    int count = A.size() * A[0].size();
    int maxR = A.size() - 1;
    int minR = 0;
    int maxC = A[0].size() - 1;
    int minC = 0;

    while(count > 0 && minC <= maxC && minR <= maxR){
        // upper wall
        for(int j = minC; j <= maxC && minC <= maxC && minR <= maxR; j++){
            res.push_back(A[minR][j]);
            // cout << A[minR][j] << " ";
            count--;
        }

        minR++;

        // right wall
        for(int i = minR; i <= maxR && minC <= maxC && minR <= maxR; i++){
            res.push_back(A[i][maxC]);
            // cout << A[i][maxC] << " ";

            count--;
        }

        maxC--;

        // bottom wall
        for(int j = maxC; j >= minC && minC <= maxC && minR <= maxR; j--){
            res.push_back(A[maxR][j]);
            // cout << A[maxR][j] << " ";

            count--;
        }

        maxR--;
        
        // left wall
        for(int i = maxR; i >= minR && minC <= maxC && minR <= maxR; i--){
            res.push_back(A[i][minC]);
            // cout << A[i][minC] << " ";

            count--;
        }

        minC++;
    }

    return res;
}

int main(int argc, char** argv){
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {1,2,3,4},
        {6,5,4,3}
    };
    spiralOrder(matrix);
}