#include <iostream>
#include <vector>
#include <string>

using namespace std;

void queen_level_BM(int bm, int cq, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }
    
    for(int i = 0; i < tb; i++){
        int b = 1 << i;
        if((b & bm) == 0){
            bm = bm | (1 << i);
            queen_level_BM(bm, cq + 1, tq, tb, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            bm = bm & (~(1 << i));
        }
    }
}

void queen_level(vector<int>& boxes, int cq, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }
    
    for(int i = 0; i < boxes.size(); i++){
        if(boxes[i] == 0){
            boxes[i] = 1;
            queen_level(boxes, cq + 1, tq, tb, asf + "b" + to_string(i) + "q" + to_string(cq) + " ");
            boxes[i] = 0;
        }
    }
}

void box_level(int cb, int tb, int tq, int bm, string asf){
    if(cb == tb){
        // cout << "base case" << endl;
        for(int i = 0; i < tq; i++){
            int b = 1 << i;
            if((b & bm) == 0){
                // cout << "Unset queen " << i << " " << bm << endl;
                return;
            }
        }

        cout << asf << endl;
        return;
    }
    
    box_level(cb + 1, tb, tq, bm, asf);

    for(int i = 0; i < tq; i++){
        int b = 1 << i;
        if((b & bm) == 0){
            bm = bm | (1 << i);
            box_level(cb + 1, tb, tq, bm, asf + "b" + to_string(cb) + "q" + to_string(i) + " ");
            bm = bm & (~(1 << i));
        }
    }
}

int main(int argc, char** argv){
    // queen_level_BM(0, 0, 2, 4, "");

    vector<int> boxes (4, 0);
    queen_level(boxes, 0, 2, 4, "");

    // box_level(0, 4, 2, 0, "");
}