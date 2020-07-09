#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool imbal_bracks(string s){
    stack<char> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        } else if(ch == ')'){
            if(st.size() > 0 && st.top() == '('){
                st.pop();
                continue;
            } else {
                return true;
            }
        } else if(ch == '}'){
            if(st.size() > 0 && st.top() == '{'){
                st.pop();
                continue;
            } else {
                return true;
            }
        } else if(ch == ']'){
            if(st.size() > 0 && st.top() == '['){
                st.pop();
                continue;
            } else {
                return true;
            }
        }
    }

    if(st.empty()){
        return false;
    } else {
        return true;
    }
}

int main(int argc, char** argv){
    string s = "[a + [b + {c + (d + e)}]]]";
    cout << imbal_bracks(s) << endl;
}