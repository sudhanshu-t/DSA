#include <iostream>
#include <stack>

using namespace std;
class Pair{
public:
    char c;
    int i;
    
    Pair(char c, int i){
        this->c = c;
        this->i = i;
    }
};

int longestValidParentheses(string s) {
    stack<Pair> st;
    int len = 0;
    
    st.push(Pair (')', -1));
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        
        if(c == '('){
            st.push(Pair (c, i));
        } else {
            if(st.size() == 0){
                st.push(Pair (c, i));
            } else if(st.top().c == ')'){
                st.push(Pair (c, i));
            } else {
                st.pop();
                int plen = i - st.top().i;
                
                len = max(len, plen);
                cout << len << " " << plen << endl;
                // st.pop();
            }
        }

        // cout << st.top().c << " " << st.top().i << endl;
    }
    
    return len;
}

int main(int argc, char** argv){
    string s;
    cin >> s;

    cout << longestValidParentheses(s) << endl;
}