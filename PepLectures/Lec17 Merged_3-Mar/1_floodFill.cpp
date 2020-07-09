#include <iostream>
#include <vector>
#include <string>

using namespace std;

void floodFillPro(int cr, int cc, int dr, int dc, vector <vector <int>>& vvi, string asf){
    if(cc == dc && cr == dr){
        cout << asf << endl;
        return;
    }

    vvi[cr][cc] = -1;

    if(cr + 1 <= dc && vvi[cr+1][cc] == 0){
        floodFillPro(cr+1, cc, dr, dc, vvi, asf + "d");
        vvi[cr+1][cc] = 0;
    }

    if(cc + 1 <= dc && vvi[cr][cc+1] == 0){
        floodFillPro(cr, cc+1, dr, dc, vvi, asf + "r");
        vvi[cr][cc+1] = 0;
    }

    if(cr - 1 >= 0 && vvi[cr-1][cc] == 0){
        floodFillPro(cr-1, cc, dr, dc, vvi, asf + "t");
        vvi[cr-1][cc] = 0;
    }

    if(cc - 1 >= 0 && vvi[cr][cc-1] == 0){
        floodFillPro(cr, cc-1, dr, dc, vvi, asf + "l");
        vvi[cr][cc-1] = 0;
    }
}

void floodFillRe(int cr, int cc, int dr, int dc, vector <vector <int>>& vvi, string asf){
    if(cc == dc && cr == dr){
        cout << asf << endl;
        return;
    }

    if(cc > dc || cr > dr || cc < 0 || cr < 0 || vvi[cr][cc] != 0){
        return;
    }

    vvi[cr][cc] = -1; // Visit
    floodFillRe(cr+1, cc, dr, dc, vvi, asf + "d");
    floodFillRe(cr-1, cc, dr, dc, vvi, asf + "t");
    floodFillRe(cr, cc-1, dr, dc, vvi, asf + "l");
    floodFillRe(cr, cc+1, dr, dc, vvi, asf + "r");
    vvi[cr][cc] = 0; // Unvisit
}

int main(int argc, char** argv){

    vector <vector <int>> vvi;

    for(int i = 0; i < 6; i++){
        vector <int> vi;
        for(int j = 0; j < 6; j++){
            vi.push_back(0);
        }

        vvi.push_back(vi);
    }

    vvi[0][1] = 1;
    vvi[1][1] = 1;
    vvi[2][1] = 1;
    vvi[4][1] = 1;
    vvi[5][1] = 1;
    vvi[1][3] = 1;
    vvi[1][4] = 1;
    vvi[2][3] = 1;
    vvi[2][4] = 1;
    vvi[4][3] = 1;
    vvi[4][4] = 1;

    floodFillPro(0, 0, 5, 5, vvi, "");
    cout << endl;
    floodFillRe(0, 0, 5, 5, vvi, "");

    return 0;
}