#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool compareString(string S, string T) {
    //write your code here

    stack<char> s1;
    stack<char> s2;

    for(int i = 0; i < S.size(); i++){
        char ch = S[i];
        if(ch != '#'){
            s1.push(ch);
        } else {
            s1.pop();
        }
    }

    for(int i = 0; i < T.size(); i++){
        char ch = T[i];
        if(ch != '#'){
            s2.push(ch);
        } else {
            s2.pop();
        }
    }

    if(s1.size() != s2.size()){
        return false;
    }

    while(s1.size() != 0){
        char ch1 = s1.top(); s1.pop();
        char ch2 = s2.top(); s2.pop();

        if(ch1 != ch2){
            return false;
        }
    }

    return true;
}

//Driver program
int main() {
    string s1; cin >> s1;
    string s2; cin >> s2;

    if(compareString(s1, s2))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}