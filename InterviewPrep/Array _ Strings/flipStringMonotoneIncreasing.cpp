#include<iostream>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input a string
// It should return required output.
int minFlipsMonoIncr(string &S) {
    if(S.size() < 2){
        return -1;
    }
    
    int a = 0, b = 0;

    if(S[0] == '0' && S[1] == '0'){
        a = 0;
        b = 1;
    }
    else if(S[0] == '0' && S[1] == '1'){
        a = 1;
        b = 0;
    }
    else if(S[0] == '1' && S[1] == '0'){
        a = 1;
        b = 2;
    }
    else if(S[0] == '1' && S[1] == '1'){
        a = 2;
        b = 1;
    }

    for(int i = 2; i < S.size(); i++){
        if(S[i] == '0'){
            b = min(a, b) + 1;
        } else {
            b = min(a, b);
            a = a+1;
        }
    }

    return b;
}

int main(int argc, char** argv){
    string s;
    cin>>s;
    cout<<minFlipsMonoIncr(s);
}