#include <iostream>
#include <string>

using namespace std;

void perm_bm(int bm, int cq, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < tb; i++){
        int b = 1 << i;
        if((bm & b) != b){
            bm ^= (1 << i);
            perm_bm(bm, cq+1, tq, tb, asf + "B" + to_string(i) + "Q" + to_string(cq) + " ");
            bm ^= (1 << i);
        }
    }
}

void comb_bm(int bm, int cq, int cb, int tq, int tb, string asf){
    if(cq == tq){
        cout << asf << endl;
        return;
    }

    for(int i = cb + 1; i < tb; i++){
        int b = 1 << i;
        if((bm & b) != b){
            bm ^= (1 << i);
            comb_bm(bm, cq+1, i, tq, tb, asf + "B" + to_string(i) + "Q" + to_string(cq) + " ");
            bm ^= (1 << i);
        }
    }
}

void comb_bm_boxonlevel(int bm, int cq, int cb, int tq, int tb, string asf){
    if(cb == tb){
        if(cq == tq){
            cout << asf << endl;
        }

        return;
    }
    comb_bm_boxonlevel(bm|(1 << cb), cq+1, cb+1, tq, tb, asf + "B" + to_string(cb) + "Q" + to_string(cq) + " ");
    comb_bm_boxonlevel(bm, cq, cb+1, tq, tb, asf);
}

int main(int argc, char** argv){
    // perm_bm(0, 0, 2, 4, "");
    // comb_bm(0, 0, -1, 2, 4, "");
    comb_bm_boxonlevel(0, 0, 0, 2, 4, "");
}