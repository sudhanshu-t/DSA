#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

void floodFill(int cr, int cc, int dr, int dc, vvi v, string asf){
    if(cr == dr && cc == dc){
        cout << asf << endl;
    }

    v[cr][cc] = -1;

    if(cc+1 <= dc && v[cr][cc+1] == 0){
        floodFill(cr, cc+1, dr, dc, v, "R->" + asf);
        v[cr][cc+1] = 0;
    }

    if(cr+1 <= dr && v[cr+1][cc] == 0){
        floodFill(cr+1, cc, dr, dc, v, "D->" + asf);
        v[cr+1][cc] = 0;
    }

    if(cc-1 >= 0 && v[cr][cc-1] == 0){
        floodFill(cr, cc-1, dr, dc, v, "L->" + asf);
        v[cr][cc-1] = 0;
    }

    if(cr-1 >= 0 && v[cr-1][cc] == 0){
        floodFill(cr-1, cc, dr, dc, v, "T->" + asf);
        v[cr-1][cc] = 0;
    }
}

void qInLevelComb(bool* boxes, int cq, int cb, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }

    for(int i = cb+1; i < tb; i++){
        if(boxes[i] == false){
            boxes[i] = true;
            qInLevelComb(boxes, cq+1, i, tq, tb, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            boxes[i] = false;
        }
    }
}


void qInLevelPerm(bool* boxes, int cq, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < tb; i++){
        if(boxes[i] == false){
            boxes[i] = true;
            qInLevelPerm(boxes, cq+1, tq, tb, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            boxes[i] = false;
        }
    }
}

int main(int argc, char** argv){

    vvi v = {
        {0,1,0,0,0,0},
        {0,1,0,1,1,0},
        {0,1,0,1,1,0},
        {0,0,0,0,0,0},
        {0,1,0,1,1,0},
        {0,1,0,0,0,0}
    };

    // floodFill(0,0,5,5,v, "");

    bool boxes[4] = {0};
    // qInLevelComb(boxes, 0, -1, 2, 4, "");
    qInLevelPerm(boxes, 0, 2, 4, "");
}