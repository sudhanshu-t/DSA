#include <iostream>
#include <string>
#include <vector>

using namespace std;

void exit_point(vector<vector<int>>& arr){
    int d = 0;
    
    int i = 0;
    int j = 0;
    while(i < arr.size() && j < arr.size()){
        if(arr[i][j] == 1)
            d = (d + 1) % arr.size();

        if(d == 0){
            j++;
        } else if(d == 1){
            i++;
        } else if(d == 2){
            j--;
        } else if(d == 3){
            i--;
        }
    }

    if(i == arr.size() && j == arr.size()){
        cout << i-1 << " " << j-1 << endl;
    } else if(j == arr.size()){
        cout << i << " " << j-1 << endl;
    } else if(i == arr.size()){
        cout << i-1 << " " << j << endl;
    }
}

int main(int argc, char** argv){
    vector<vector<int>> arr = {
        {0,0,1,0},
        {1,0,0,1},
        {0,0,0,0},
        {1,0,1,0}
    };

    exit_point(arr);
}