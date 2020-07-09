// DP sol at bottom

#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
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
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

// DP Solution

/* import java.util.*;

class Solution {
    public int longestValidParentheses(String s) {
        int[] dp = new int[s.length()];
        
        // dp[0] = 0;
        // if(s.charAt(0) == ')'){
        //     dp[1] = 0;
        // } else if(s.charAt(1) == ')') {
        //     dp[1] = 2;
        // }
        
        int mymax = 0;
        
        for(int i = 1; i < s.length(); i++){
            char c = s.charAt(i);
            
            if(c == '('){
                dp[i] = 0;
            } else {
                if(s.charAt(i-1) == '('){
                    dp[i] = (i-2 >= 0? dp[i-2]: 0) + 2;
                } else {
                    if(i-dp[i-1] > 0 && s.charAt(i-1 - dp[i-1]) == '('){
                        dp[i] = dp[i-1] + 2 + (i-2 - dp[i-1] >= 0 ? dp[i-2 - dp[i-1]] : 0);
                    }
                }
            }
            
            mymax = Math.max(mymax, dp[i]);
        }
        
        // for(int i = 0; i < dp.length; i++){
        //     System.out.print(dp[i] + " ");
        // }
        return mymax;
    }
}
*/