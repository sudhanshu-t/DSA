#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getss(string str){
    if(str.size() == 0){
        vector<string> br;
        br.push_back("");

        return br;
    }

    vector<string> rr = getss(str.substr(1));
    vector<string> mr;

    for(int i = 0; i < rr.size(); i++){
        mr.push_back("-" + rr[i]);
        mr.push_back(str[0] + rr[i]);    
    }

    return mr;
}

vector<string>* getPath(int cr, int cc, int dr, int dc){
    if(cc == dc && cr == dr){
        vector<string>* br;
        br->push_back("");

        return br;
    }

    vector<string>* rr1;
    vector<string>* rr2;
    if(cc+1 <= dc){
        rr1 = getPath(cr, cc+1, dr, dc);
    }
    if(cr+1 <= dr){
        rr2 = getPath(cr+1, cc, dr, dc);
    }

    vector<string>* mr = new vector<string>();

    for(int i = 0; i < rr1->size(); i++){
        mr->push_back('H' + (*rr1)[i]);
    }

    for(int i = 0; i < rr2->size(); i++){
        mr->push_back('V' + (*rr2)[i]);
    }

    return mr;
}

vector<string> getPath2(int cr, int cc, int dr, int dc){
    if(cr == dr && cc == dc){
        vector<string> br;
        br.push_back("");

        return br;
    }

    if(cr > dr || cc > dc){
        vector<string> br;
        return br;
    }
    
    vector<string> rr1 = getPath2(cr, cc+1, dr, dc);
    vector<string> rr2 = getPath2(cr+1, cc, dr, dc);

    vector<string> mr;

    for(int i = 0; i < rr1.size(); i++){
        mr.push_back('H' + rr1[i]);
    }

    for(int i = 0; i < rr2.size(); i++){
        mr.push_back('V' + rr2[i]);
    }

    return mr;
}

vector<string> stair(int n){
    if(n == 0){
        vector<string> br;
        br.push_back("");

        return br;
    }

    vector<string> r1;
    vector<string> r2;
    vector<string> r3;

    if(n-1 >= 0)
        r1 = stair(n-1);
    if(n-2 >= 0)
        r2 = stair(n-2);
    if(n-3 >= 0)
        r3 = stair(n-3);

    vector<string> mr;

    for(int i = 0; i < r1.size(); i++){
        mr.push_back(to_string(1) + r1[i]);
    }

    for(int i = 0; i < r2.size(); i++){
        mr.push_back(to_string(2) + r2[i]);
    }

    for(int i = 0; i < r3.size(); i++){
        mr.push_back(to_string(3) + r3[i]);
    }

    return mr;    
}
int main(int argc, char** argv){
    // vector<string> str = getss("abc");
    // for(int i = 0; i < str.size(); i++){
    //     cout << str[i] << " ";
    // }
    // cout << endl;

//===== Using pointer type vector ===============
    // vector<string>* paths = getPath(0, 0, 3, 3);

    // for(int i = 0; i < paths->size(); i++){
    //     cout << (*paths)[i] << endl;
    // }
//====================

    // vector<string> paths = getPath2(0,0,2,2);
    
    // for(int i = 0; i < paths.size(); i++){
    //     cout << paths[i] << endl;
    // }


    vector<string> paths = stair(3);
    for(int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }

    cout << paths.size() << endl;
}