#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 0 || s.size() == 1){
            return s.size();
        }
        
        vector<vector<int>> strg (s.size(), vector<int> (s.size(), 0));
        
        for(int x = 0; x < strg.size(); x++){
            for(int i = 0, j = x; j < strg[0].size(); i++, j++){
                if(x == 0){
                    strg[i][j] = 1;
                    continue;
                }
                
                if(s[i] == s[j]){
                    strg[i][j] = strg[i+1][j-1] + 2;
                } else {
                    strg[i][j] = max(strg[i+1][j], strg[i][j-1]);
                }
            }
        }
        
        return strg[0][strg[0].size() - 1];
    }
};