#include <iostream>
#include <string>
using namespace std;

string remDupRec(string s){
    if(s.size() == 0){
        return "";
    }
    
    int initSize = s.size();
    
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i+1]){
            string bef = s.substr(0, i);
            
            while(i + 1 < s.size() && s[i] == s[i+1]){
                i++;
            }

            string aft = s.substr(i+1);

            s = bef + aft;
        }
    }

    if(s.size() == initSize){
        return s;
    }

    return remDupRec(s);
}

int main(int argc, char** argv){
    string s;
    cin >> s;

    cout << remDupRec(s) << endl;
}