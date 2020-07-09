#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

int eval(int v1, int v2, char op){
    int rv = -1;

    switch(op)
    {
    case '^':
        rv = pow(v1, v2);
        break;

    case '*':
        rv = v1 * v2;
        break;

    case '/':
        rv = v1 / v2;
        break;

    case '+':
        rv = v1 + v2;
        break;

    case '-':
        rv = v1 - v2;
        break;

    default:
        break;
    }

    return rv;
}

int postfix_eval(string s){
    stack<int> vs;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch >= '0' && ch <= '9'){
            vs.push(ch - '0');
        } else {
            int v2 = vs.top(); vs.pop();
            int v1 = vs.top(); vs.pop();

            vs.push(eval(v1, v2, ch));
        }
    }

    return vs.top();
}

string postfix_to_infix(string s){
    stack<string> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch >= '0' && ch <= '9'){
            string s = string() + ch;
            st.push(s);
        } else {
            string s2 = st.top(); st.pop();
            string s1 = st.top(); st.pop();

            string s = string(1, ch);
            st.push('(' + s1 + s + s2 + ')');
        }
    }

    return st.top();
}

string postfix_to_prefix(string s){
    stack<string> st;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(ch >= '0' && ch <= '9'){
            string s = string() + ch;
            st.push(s);
        } else {
            string s2 = st.top(); st.pop();
            string s1 = st.top(); st.pop();

            string s = string(1, ch);
            st.push(s + s1 + s2);
        }
    }

    return st.top();
}

int main(int argc, char** argv){
    cout << postfix_eval("823/+21^13+*+") << endl;
    cout << postfix_to_infix("823/+21^13+*+") << endl;
    cout << postfix_to_prefix("24/32^-") << endl;
    
    return 0;
}