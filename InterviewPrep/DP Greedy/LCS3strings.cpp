#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS3(string s1, string s2, string s3){
    vector<vector<vector<int>>> strg (s1.size() + 1, 
           vector<vector<int>> (s2.size() + 1, vector<int> (s3.size() + 1, 0)));
           
    for(int i = strg.size() - 1; i >= 0; i--){
        for(int j = strg[0].size() - 1; j >= 0; j--){
            for(int k = strg[0][0].size() - 1; k >= 0; k--){
                if(i == strg.size() - 1 || j == strg[0].size() - 1 || k == strg[0][0].size() - 1){
                    strg[i][j][k] = 0;
                    continue;
                }
                
                if(s1[i] == s2[j] && s2[j] == s3[k]){
                    strg[i][j][k] = strg[i+1][j+1][k+1] + 1;
                } else {
                    strg[i][j][k] = max(strg[i+1][j][k], max(strg[i][j+1][k], strg[i][j][k+1]));
                }
            }
        }
    }
    
    // for(int i = 0; i < strg.size(); i++){
    //     for(int j = 0; j < strg[0].size(); j++){
    //         for(int k = 0; k < strg[0][0].size(); k++){
    //             cout << strg[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl << endl;
    // }
    
    return strg[0][0][0];
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int m, n, k;
	    cin >> m >> n >> k;
	    
	    string s1 = "", s2 = "", s3 = "";
	    
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
	    
	    for(int i = 0; i < k; i++){
	        char ch;
	        cin >> ch;
	        s3 += ch;
	    }
	    
	    cout << LCS3(s1, s2, s3) << endl;
	}
	return 0;
}