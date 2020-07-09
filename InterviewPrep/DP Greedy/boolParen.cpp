#include <iostream>
#include <vector>
using namespace std;

class Pair{
public:
    int tc;
    int fc;
    int ac;
    
    Pair(int t, int f, int a){
        tc = t;
        fc = f;
        ac = a;
    }
};

int M = 1003;

int boolParen(string operands, string operators){
    vector<vector<Pair*>> strg (operands.size(), vector<Pair*> (operands.size()));
    
    for(int x = 0; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(x == 0){
                int tc, fc, ac;
                if(operands[i] == 'T'){
                    tc = 1;
                    fc = 0;
                    ac = 1;
                } else {
                    tc = 0;
                    fc = 1;
                    ac = 1;
                }
                
                Pair* p = new Pair(tc, fc, ac);
                strg[i][j] = p;
                
                continue;
            }
            
            int tc = 0, fc = 0, ac = 0;
            for(int k = i; k < j; k++){
                if(operators[k] == '&'){
                    tc += ((strg[i][k]->tc)%M * (strg[k+1][j]->tc)%M) % M;
                    fc += ((strg[i][k]->ac)%M - ((strg[i][k]->tc)%M * (strg[k+1][j]->tc)%M) % M)%M;
                } else if(operators[k] == '|'){
                    tc += ((strg[i][k]->ac)%M - ((strg[i][k]->fc)%M * (strg[k+1][j]->fc)%M) % M)%M;
                    fc += (strg[i][k]->fc * strg[k+1][j]->fc)%M;
                } else if(operators[k] == '^'){
                    tc += (((strg[i][k]->fc)%M * (strg[k+1][j]->tc)%M) % M + ((strg[i][k]->tc)%M * (strg[k+1][j]->fc)%M) % M)%M;
                    fc += (((strg[i][k]->tc)%M * (strg[k+1][j]->tc)%M) % M + ((strg[i][k]->fc)%M * (strg[k+1][j]->fc)%M) % M)%M;
                }
            }

            ac = tc + fc;
            Pair* p = new Pair(tc, fc, ac);
            strg[i][j] = p;
        }
    }

    // for(int i = 0; i < strg.size(); i++){
    //     for(int j = 0; j < strg.size(); j++){
    //         Pair* p = strg[i][j];
    //         cout << p->tc << " ";
    //     }
    //     cout << endl;
    // }

    return strg[0][strg.size() - 1]->tc;
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    string operands = "", operators = "";
	    for(int i = 0; i < n; i++){
	        char ch;
	        cin >> ch;
	        
	        if(ch == 'T' || ch == 'F'){
	            operands += ch;
	        } else {
	            operators += ch;
	        }
	    }

        // cout << endl << operands << " " << operators << endl;
	    
	    cout << boolParen(operands, operators) << endl;
	}
	return 0;
}