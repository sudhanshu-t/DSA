#include <iostream>
#include <stack>
#include <string>
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

int prefix_eval(string s){
    stack<int> vs;

    for(int i = s.size() - 1; i >= 0; i--){
        char ch = s[i];

        if(ch >= '0' && ch <= '9'){
            vs.push(ch - '0');
        } else {
            int v1 = vs.top(); vs.pop();
            int v2 = vs.top(); vs.pop();

            vs.push(eval(v1, v2, ch));
        }
    }

    return vs.top();
}

string pre_to_in(string s){
    stack<string> st;
    
    for(int i = s.size() - 1; i >= 0; i--){
        char ch = s[i];

        if(ch >= '0' && ch <= '9'){
            string s = string() + ch;

            st.push(s);
        } else {
            string v1 = st.top(); st.pop();
            string v2 = st.top(); st.pop();

            string s = string(1, ch);

            st.push('(' + v1 + s + v2 + ')');
        }
    }

    return st.top();
}

string pre_to_post(string s){
    stack<string> st;

    for(int i = s.size() - 1; i >= 0; i--){
        char ch = s[i];

        if(ch >= '0' && ch <= '9'){
            string s = string(1, ch);
            st.push(s);
        } else {
            string s = string() + ch;
            string v1 = st.top(); st.pop();
            string v2 = st.top(); st.pop();

            st.push(v1 + v2 + s);
        }
    }

    return st.top();
}

int main(int argc, char** argv){
    string s = "-/24^32";

    cout << prefix_eval(s) << endl;
    cout << pre_to_in(s) << endl;
    cout << pre_to_post(s) << endl;
}