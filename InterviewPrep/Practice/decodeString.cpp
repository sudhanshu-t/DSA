#include <iostream>
#include <string>
#include <stack>

using namespace std;

string decodeString(string s) {
    stack<char> st;
    string ans;

    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c == '['){
            st.push(c);
        } else if (c >= 48 && c <= 57){
            st.push(c);
        } else if (c >= 65 && c <= 90){
            st.push(c);
        } else if (c >= 97 && c <= 122){
            st.push(c);
        } else {
            string curr, res;
            char top = st.top();
            st.pop();

            while(top != '['){
                curr = top + curr;
                
                top = st.top();
                st.pop();
            }

            int num = 0;
            int power = 1;
            
            top = st.top();

            while(st.size() != 0 && (top >= 48 && top <= 57)){
                st.pop();
                int d = top - '0';
                
                num += d * power;
                power *= 10;
                
                if(st.size() != 0) top = st.top();
            }

            for(int i = 0; i < num; i++){
                res += curr;
            }

            for(int i = 0; i < res.size(); i++){
                st.push(res[i]);
            }
        }
    }

    while(st.size() != 0){
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}

int main(){
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;
}