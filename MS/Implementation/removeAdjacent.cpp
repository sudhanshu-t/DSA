#include <iostream>
using namespace std;

string rem(string& s){
    if(s.size() == 1){
        return s;
    }

    if(s.size() == 2){
        if(s[0] == s[1]){
            return "";
        } else {
            return s;
        }
    }

    while(s.size() > 2 && s[0] == s[1]){
        s = s.substr(1);
    }

    string ss = s.substr(1);

    string remS = rem(ss);

    if(remS.size() == 0){
        return "";
    } else {
        if(remS[0] == s[0]){
            return s.substr(2);
        } else {
            return remS;
        }
    }
}

bool main(){
    string s = "accaccbccb";
    cout << rem(s) << endl;
}