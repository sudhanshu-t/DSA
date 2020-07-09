#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(vector<vector<int>>& arr, int i, int j){
    int temp = arr[i][j];
    arr[i][j] = arr[j][i];
    arr[j][i] = temp;
}

void swap2(vector<vector<int>>& arr, int i, int j){
    int temp = arr[i][j];
    arr[i][j] = arr[arr.size() - i - 1][j];
    arr[arr.size() - i - 1][j] = temp;
}

void rot_mat(vector<vector<int>>& arr){
    // Transpose
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size(); j++){
            swap(arr, i, j);
        }
    }

    // Row Reverse
    for(int j = 0; j < arr.size(); j++){
        for(int i = 0; i < arr.size() / 2; i++){
            swap2(arr, i, j);
        }
    }
}

int main(int argc, char** argv){
    vector<vector<int>> arr = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    rot_mat(arr);
}