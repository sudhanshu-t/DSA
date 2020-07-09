#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            s = left+right;
            i--;
        }
    }
    
    stack<int> num;
    stack<char> operators;
    unordered_map<char, int> map;
    map['+'] = 1;
    map['-'] = 1;
    map['/'] = 2;
    map['*'] = 2;
    
    cout << s << endl;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            cout << "Adding char " << s[i] << endl;
            while(operators.size() != 0 && map[operators.top()] >= map[s[i]]){
                char c = operators.top();
                operators.pop();
                
                int n2 = num.top(); num.pop();
                int n1 = num.top(); num.pop();
                cout << "n1 is " << n1 << " & n2 is " << n2 << endl;

                int ans;
                
                if(c == '+'){
                    ans = n1+n2;
                } else if(c == '-'){
                    ans = n1-n2;
                } else if(c == '*'){
                    ans = n1*n2;
                } else if(c == '/'){
                    ans = n1/n2;
                }
                
                num.push(ans);
            }
            operators.push(s[i]);
        } else {
            int n = 0;
            int idx = i;
            while(s[idx]-'0' >= 0 && s[idx]-'0' <= 9){
                int d = (s[idx]-'0');
                n = 10*n + d;
                idx++;
            }
            
            cout << "n is " << n << endl;
            num.push(n);
            
            i = idx-1;
        }
    }
    
    while(operators.size() != 0 && num.size() > 1){
        char c = operators.top();
        operators.pop();

        int n2 = num.top(); num.pop();
        int n1 = num.top(); num.pop();
        
        cout << "n1 is " << n1 << " & n2 is " << n2 << endl;
        int ans;
        
        if(c == '+'){
            ans = n1+n2;
        } else if(c == '-'){
            ans = n1-n2;
        } else if(c == '*'){
            ans = n1*n2;
        } else if(c == '/'){
            ans = n1/n2;
        }
        
        num.push(ans);
    }

    if(operators.size() != 0){
        char c = operators.top();
        operators.pop();
        
        if(c == '-'){
            return -num.top();
        }
    }
    
    return num.top();
}

int main(){
    string s = "-2+3/3*6";
    cout << calculate(s) << endl;
}