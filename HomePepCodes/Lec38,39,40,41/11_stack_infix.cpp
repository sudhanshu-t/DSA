#include <iostream>
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

int get_priority(char ch){
    int rv = -1;

    switch (ch)
    {
    case '^':
        rv = 3;
        break;

    case '*':
    case '/':
        rv = 2;
        break;

    case '+':
    case '-':
        rv = 1;
        break;
    
    default:
        break;
    }

    return rv;
}

int infix_eval(string s){
    stack<int> vs;
    stack<char> os;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];

        if(ch >= '0' && ch <= '9'){
            vs.push(ch - '0');
        } else if(ch == '(') {
            os.push(ch);
        } else if(ch == ')'){
            while(os.top() != '('){
                int v2 = vs.top(); vs.pop();
                int v1 = vs.top(); vs.pop();
                char op = os.top(); os.pop();

                vs.push(eval(v1, v2, op));
            }

            os.pop();
        } else {
            // operators
            while(os.size() > 0 &&
                  os.top() != '(' &&
                  get_priority(os.top()) >= get_priority(ch)){
                        int v2 = vs.top(); vs.pop();
                        int v1 = vs.top(); vs.pop();
                        char op = os.top(); os.pop();

                        vs.push(eval(v1, v2, op));
                  }

            os.push(ch);
        }
    }
    while(os.size() > 0){
        int v2 = vs.top(); vs.pop();
        int v1 = vs.top(); vs.pop();
        char op = os.top(); os.pop();

        vs.push(eval(v1, v2, op));
    }

    return vs.top();
}

string infix_to_postfix(string s){
    stack<char> os;
    string res;

    for(int i = 0; i < s.size(); i++){
        char ch = s[i];

        if(ch >= '0' && ch <= '9'){
            res += ch;
        } else if(ch == '('){
            os.push(ch);
        } else if(ch == ')'){
            while(os.top() != '('){
                res += os.top(); os.pop();
            }

            os.pop();
        } else {
            while(os.size() > 0 &&
                  os.top() != '(' &&
                  get_priority(os.top()) >= get_priority(ch)){
                      res += os.top(); os.pop();
                  }
            
            os.push(ch);
        }
    }

    while(os.size() != 0){
        res += os.top();
        os.pop();
    }

    return res;
}

string infix_to_prefix(string s){
    for(int i = 0; i < s.size() / 2; i++){
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            s[i] = ')';
        } else if(s[i] == ')'){
            s[i] = '(';
        }
    }

    s = infix_to_postfix(s);

    for(int i = 0; i < s.size() / 2; i++){
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            s[i] = ')';
        } else if(s[i] == ')'){
            s[i] = '(';
        }
    }

    return s;
}

int main(int argc, char** argv){
    string s = "8+2/3+2^1*(1+3)";
    cout << infix_eval(s) << endl;
    cout << infix_to_postfix(s) << endl;
    cout << infix_to_prefix(s) << endl;
}