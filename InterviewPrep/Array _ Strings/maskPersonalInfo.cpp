#include<iostream>
using namespace std;

string maskPII(string &S) {
    bool format = false;
    bool isString = false;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == '@'){
            isString = true;
            break;
        }

        if(S[i] == '-'){
            format = true;
        }
    }

    if(isString){
        int end = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] >= 65 && S[i] <= 90){
                S[i] = S[i] + 32;
            }

            if(S[i+1] == '@'){
                end = i;
                cout << end << endl;
            }
        }

        string s (1, S[0]);
        S = s + "*****" + S.substr(end);
    } else {
        if(format){
            
        }
    }

    return S;
}

int main(int argc, char** argv){
    string str;
    cin>>str;
    cout<<maskPII(str);
}