#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> gmpmm(int cr, int cc, int er, int ec){

    if(cr == er && cc == ec){
        vector <string> bres;
        bres.push_back("");

        return bres;
    }

    vector <string> mres;

    for(int i = 1; cc + i <= ec; i++){
        vector <string> hpaths = gmpmm(cr, cc + i, er, ec);

        // string s = string(1, i);
        for(int j = 0; j < hpaths.size(); j++){
            mres.push_back("h" + to_string(i) + hpaths[j]);
        }
    }

    for(int i = 1; cr + i <= er; i++){
        vector <string> vpaths = gmpmm(cr + i, cc, er, ec);

        // string s = string(1, i);
        for(int j = 0; j < vpaths.size(); j++){
            mres.push_back("v" + to_string(i) + vpaths[j]);
        }
    }

    for(int i = 1; (cc + i <= ec) && (cr + i) <= er; i++){
        vector <string> dpaths = gmpmm(cr + i, cc + i, er, ec);

        // string s = string(1, i);
        for(int j = 0; j < dpaths.size(); j++){
            mres.push_back("d" + to_string(i) + dpaths[i]);
        }
    }

    return mres;
}

int main(int argc, char** argv){
    vector <string> paths = gmpmm(0,0,2,2);

    cout << paths.size() << endl;
    for(int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }

    return 0;
}