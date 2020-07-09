#include <iostream>
#include <string>
#include <vector>

#define vvi vector<vector<int>>

using namespace std;

bool is_valid(vvi& matrix, int i, int j){
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size()){
        return false;
    }

    if(matrix[i][j] != 0){
        return false;
    }

    return true;
}

void floodfill(vvi& matrix, int cc, int cr, int dc, int dr, string psf){
    if(cc == dc && cr == dr){
        cout << psf << endl;
        return;
    }    
    
    matrix[cr][cc] = 2;

    if(is_valid(matrix, cr + 1, cc)){
        floodfill(matrix, cc, cr + 1, dc, dr, psf + "Down ");
    }

    if(is_valid(matrix, cr - 1, cc)){
        floodfill(matrix, cc, cr - 1, dc, dr, psf + "Up ");
    }

    if(is_valid(matrix, cr, cc + 1)){
        floodfill(matrix, cc + 1, cr, dc, dr, psf + "Right ");
    }

    if(is_valid(matrix, cr, cc - 1)){
        floodfill(matrix, cc - 1, cr, dc, dr, psf + "Left ");
    }
    
    matrix[cr][cc] = 0;
}

int main(int argc, char** argv){
    vector<vector<int>> v;

    for(int i = 0; i < 6; i++){
        vector <int> vi;
        for(int j = 0; j < 6; j++){
            vi.push_back(0);
        }

        v.push_back(vi);
    }

    v[0][1] = 1;
    v[1][1] = 1;
    v[2][1] = 1;
    v[4][1] = 1;
    v[5][1] = 1;
    v[1][3] = 1;
    v[1][4] = 1;
    v[2][3] = 1;
    v[2][4] = 1;
    v[4][3] = 1;
    v[4][4] = 1;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }

        cout << endl;
    }

    floodfill(v, 0, 0, 5, 5, "");
}