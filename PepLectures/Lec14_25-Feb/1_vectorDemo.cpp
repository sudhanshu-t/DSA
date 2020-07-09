#include <iostream>
#include <string>
#include <vector>
using namespace std;

// String Subsequence

// abc => ---, --c, -b-, -bc, a--, a-c, ab-, abc
// ab  => --, -b, a-, ab
// g(abc) = g(ab)- + g(ab)c

vector <string> getss(string str, int ep){
    if(ep == -1){
        vector <string> bres;
        bres.push_back("");
        return bres;
    }
    
    char ch = str[ep];
    vector <string> rres = getss(str, ep - 1);
    vector <string> mres;

    for(int i = 0; i < rres.size(); i++){
        mres.push_back(rres[i] + "-");
        mres.push_back(rres[i] + ch);
    }

    return mres;
}

vector <string> getPath(int cr, int cc, int er, int ec){
    if(cc > ec || cr > er){
        vector <string> bres;
        return bres;
    }

    if(cc == ec && cr == er){
        vector <string> bres;
        bres.push_back("");

        return bres;
    }

    vector <string> s1 = getPath(cr, cc + 1, er, ec);
    vector <string> s2 = getPath(cr + 1, cc, er, ec);

    vector <string> mres;

    for(int i = 0; i < s1.size(); i++){
        s1[i] = "r" + s1[i];
        mres.push_back(s1[i]);
    }

    for(int i = 0; i < s2.size(); i++){
        s2[i] = "d" + s2[i];
        mres.push_back(s2[i]);
    }

    return mres;
}

vector <string> getPath1(int cr, int cc, int er, int ec){
    
}

vector <string> stair(int n){
    if(n == 0){
        vector <string> bres;
        bres.push_back("");

        return bres;
    }   
    
    vector <string> r1 = stair(n-1);
    vector <string> r2, r3;

    /// Proactive approach (faster than Reactive appr where we make calls w/o checking whether they are valid or not and then manage -ve n cases in abse case by returning zero paths)
    if(n-2 >= 0)
        r2 = stair(n-2);
    if(n-3 >= 0)
        r3 = stair(n-3);

    vector <string> mres;

    for(int i = 0; i < r1.size(); i++){
        mres.push_back('1' + r1[i]);
    }

    for(int i = 0; i < r2.size(); i++){
        mres.push_back('2' + r2[i]);
    }

    for(int i = 0; i < r3.size(); i++){
        mres.push_back('3' + r3[i]);
    }

    return mres;
}

int main(int argc, char** argv){
    string str = "abcd";

    vector <string> res = getss(str, str.size() - 1);


    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    // vector <string> res = getPath(0, 0, 3, 3);

    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << endl;
    // }

    // vector <string> res = stair(7);

    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << endl;
    // }

    // cout << endl << res.size() << endl;

    // return 0;
}