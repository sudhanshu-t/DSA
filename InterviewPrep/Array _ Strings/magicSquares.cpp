#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Do not make changes to main
// This function takes as input an array and integer k.
// It should print required output.
bool isMS(int r, int c, vector<vector<int>>& grid){
    if(r+2 >= grid.size() || c+2 >= grid[0].size()){
        return false;
    }
    
    // Columns
    for(int j = c; j < c+3; j++){
        int sum = 0;
        for(int i = r; i < r+3; i++){
            sum += grid[i][j];
        }

        if(sum != 15){
            return false;
        }
    }

    // Rows
    for(int i = r; i < r+3; i++){
        int sum = 0;
        for(int j = c; j < c+3; j++){
            sum += grid[i][j];
        }

        if(sum != 15){
            return false;
        }
    }

    // Diagonals
    int sum = 0;
    for(int i = r, j = c; i < r+3 && j < c+3; i++, j++){
        sum += grid[i][j];
    }

    if(sum != 15){
        return false;
    }

    sum = 0;
    for(int i = r+2, j = c; i >= r && j < c+3; i--, j++){
        sum += grid[i][j];
    }

    if(sum != 15){
        return false;
    }

    return true;
}

int numMagicSquaresInside(vector<vector<int> > &grid) {
    // Write your code here
    int count = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i+1][j+1] == 5){
                if(isMS(i, j, grid)){
                    count++;
                }
            }
        }
    }

    return count;
}

int main(int argc, char** argv){
    int r, c;
    cin>>r>>c;
    vector<vector<int> > Input(r, vector<int> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>Input[i][j];
        }
    }
    cout<<numMagicSquaresInside(Input);
}