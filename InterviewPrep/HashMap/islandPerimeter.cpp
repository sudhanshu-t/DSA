#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>>& v, int i, int j){
    if(i < 0 || i == v.size() || j < 0 || j == v[0].size()){
        return true;
    } else if(v[i][j] == 0){
        return true;
    }

    return false;
}

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a matrix.
// It should return perimeter value.
int islandPerimeter(vector<vector<int> >& v)
{
    //Write your code here
    int count = 0;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] == 1){
                // T
                if(isValid(v, i-1, j)){
                    count++;
                }
                // L
                if(isValid(v, i, j-1)){
                    count++;
                }
                // D
                if(isValid(v, i+1, j)){
                    count++;
                }
                // R
                if(isValid(v, i, j+1)){
                    count++;
                }
            }
        }
    }

    return count;
}
int main(int argc, char** argv){
    int row,col;
    cin>>row>>col;
    vector<vector<int> > v (row, vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cin>>v[i][j];
    }

    cout<<islandPerimeter(v);
}