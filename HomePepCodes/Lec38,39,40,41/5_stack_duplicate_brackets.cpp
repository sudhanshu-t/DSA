// Code to find redundant brackets

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool dup_brack(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == ')'){
            if(st.top() == '('){
                return true;
            } else {
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        } else {
            st.push(ch);
        }
    }

    return false;
}

int main(int argc, char** argv){
    string s = "((a+b) + (((c + d) + e)))";
    cout << dup_brack(s) << endl;

    return 0;
}