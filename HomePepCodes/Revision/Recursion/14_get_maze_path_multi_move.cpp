#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>* gmpmm(int sr, int sc, int dr, int dc){
    if(sr == dr && sc == dc){
        vector<string>* bres = new vector<string>;
        bres->push_back("");

        return bres;
    }
    
    vector<string>* mres = new vector<string>;

    // Rows
    for(int i = 1; sr + i <= dr; i++){
        vector<string>* rres_r = gmpmm(sr + i, sc, dr, dc);
        
        for(int p = 0; p < rres_r->size(); p++){
            mres->push_back("V" + to_string(i) + rres_r->at(p));
        }
    }

    // Columns
    for(int i = 1; sc + i <= dc; i++){
        vector<string>* rres_c = gmpmm(sr, sc + i, dr, dc);
        
        for(int p = 0; p < rres_c->size(); p++){
            mres->push_back("H" + to_string(i) + rres_c->at(p));
        }
    }

    // Diagonals
    for(int i = 1, j = 1; sr + i <= dr && sc + j <= dc; i++, j++){
        vector<string>* rres_d = gmpmm(sr + i, sc + j, dr, dc);

        for(int p = 0; p < rres_d->size(); p++){
            mres->push_back("D" + to_string(i) + rres_d->at(p));
        }
    }

    return mres;
}

int main(int argc, char** argv){
    vector<string>* v = gmpmm(0, 0, 2, 2);

    for(int i = 0; i < v->size(); i++){
        cout << v->at(i) << endl;
    }

    return 0;
}