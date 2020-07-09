#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int validParen(string s){
    vector<int> strg (s.size());
    
    int globalMax = INT_MIN;
    strg[0] = 0;
    
    for(int i = 1; i < strg.size(); i++){
        if(s[i] == '('){
            strg[i] = 0;
        } else {
            if(s[i-1] == '('){
                strg[i] = (i-2 >= 0 ? strg[i-2] : 0) + 2;
            } else if(i-1 - strg[i-1] >= 0 && s[i-1 - strg[i-1]] == '('){
                strg[i] = strg[i-1] + 2 + (i-2 - strg[i-1] >= 0) ? strg[i-2 - strg[i-1]] : 0;
            }
        }
        
        globalMax = max(globalMax, strg[i]);
    }
    
    return globalMax;
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    string s = "";
	    
	    for(int i = 0; i < n; i++){
	        char ch;
	        cin >> ch;
	        
	        s += ch;
	    }
	    
	   // cout << s << endl;
	    
	    cout << validParen(s) << endl;
	}
	return 0;
}