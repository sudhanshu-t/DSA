#include <iostream>
#include <string>

using namespace std;

void permBM(int bm , int cq, string asf, int tq, int tb){
    if(cq > tq){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < tb; i++){
        int b = 1 << (tb - i);
        if((b & bm) == 0){
            bm = bm | (1 << (tb-i));

            permBM(bm, cq + 1, asf + "b" + to_string(i) + "q" + to_string(cq) + " ", tq, tb);

            bm = bm & (~(1 << (tb-i)));
        }
    }
}

void comb(int bm , int cq, string asf, int tq, int tb){
    if(cq > tq){
        cout << asf << endl;
        return;
    }

    for(int i = 0; i < tb; i++){
        int b = 1 << (tb - i);
        if((b & bm) == 0){
            bm = bm | (1 << (tb-i));

            comb(bm, cq + 1, asf + "b" + to_string(i) + "q" + to_string(cq) + " ", tq, tb - i);

            bm = bm & (~(1 << (tb-i)));
        }
    }
}

// Having boxes on level
void comb1(int qpsf, int cb, int tq, int tb, string asf){
    if(cb == tb){
        if(qpsf == tq){
            cout << asf << endl;
        }
        return;
    }

    comb1(qpsf + 1, cb + 1, 2, 4, asf + "b" + to_string(cb) + "q" + to_string(qpsf) + " ");
    comb1(qpsf, cb + 1, 2, 4, asf);
}

// vector <vector <string>> mango()

int main(int argc, char** argv){
    // permBM(0, 1, "", 2, 4);
    comb(0, 1, "", 2, 4);
    // comb1(0, 0, 2, 4, "");
}