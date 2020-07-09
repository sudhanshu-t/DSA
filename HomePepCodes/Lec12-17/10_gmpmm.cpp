#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> gmpmm(int cr, int cc, int dr, int dc){
    if(cr == dr && cc == dc){
        vector<string> br;
        br.push_back("");

        return br;
    }

    vector<string> mr;

    for(int i = 1; cc + i <= dc; i++){
        vector<string> r1 = gmpmm(cr, cc+i, dr, dc);

        for(int j = 0; j < r1.size(); j++){
            mr.push_back("H" + to_string(i) + r1[j]);
        }
    }

    for(int i = 1; cr + i <= dr; i++){
        vector<string> r2 = gmpmm(cr+i, cc, dr, dc);

        for(int j = 0; j < r2.size(); j++){
            mr.push_back("V" + to_string(i) + r2[j]);
        }
    }

    for(int i = 1; cr+i <= dr && cc+i <= dc; i++){
        vector<string> r3 = gmpmm(cr+i, cc+i, dr, dc);

        for(int j = 0; j < r3.size(); j++){
            mr.push_back("D" + to_string(i) + r3[j]);
        }
    }

    return mr;
}

int main(int argc, char** argv){
    vector<string> paths = gmpmm(0,0,2,2);

    cout << paths.size() << endl;

    for(int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }
}