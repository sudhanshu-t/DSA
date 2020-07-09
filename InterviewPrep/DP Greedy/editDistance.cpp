#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ed(string s1, string s2){
    vector<vector<int>> strg (s1.size() + 1, vector<int> (s2.size() + 1));
    
    for(int i = strg.size() - 1; i >= 0; i--){
        for(int j = strg[0].size() - 1; j >= 0; j--){
            if(i == strg.size() - 1 && j == strg[0].size() - 1){
                strg[i][j] = 0;
            } else if(i == strg.size() - 1){
                strg[i][j] = strg[0].size() - j - 1;
            } else if(j == strg[0].size() - 1){
                strg[i][j] = strg.size() - i - 1;
            }
            
            else {
                if(s1[i] == s2[j]){
                    strg[i][j] = strg[i+1][j+1];
                } else {
                  strg[i][j] = min(strg[i+1][j], min(strg[i][j+1], strg[i+1][j+1])) + 1;
                }
            }
        }
    }
    
    return strg[0][0];
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int m, n;
	    cin >> m >> n;
	    
	    string s1 = "", s2 = "";
	    
	    for(int i = 0; i < m; i++){
	        char ch;
	        cin >> ch;
	        s1 += ch;
	    }
	    
	    for(int i = 0; i < n; i++){
	        char ch;
	        cin >> ch;
	        s2 += ch;
	    }
	    
	    cout << ed(s1, s2) << endl;
	}
	return 0;
}