#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double knightProbability(int n, int x, int y, int k){
    vector<vector<vector<double>>> strg (k + 1, vector<vector<double>> (n, vector<double> (n)));
    
    for(int k = 0; k < strg.size(); k++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if(k == 0){
                    strg[k][x][y] = 1;
                    continue;
                }
                
                double numr = 0;
                if(x - 2 >= 0 && y + 1 < n){
                    numr += strg[k - 1][x - 2][y + 1];
                }
                if(x - 2 >= 0 && y - 1 >= 0){
                    numr += strg[k - 1][x - 2][y - 1];
                }
                if(x - 1 >= 0 && y + 2 < n){
                    numr += strg[k - 1][x - 1][y + 2];
                }
                if(x - 1 >= 0 && y - 2 >= 0){
                    numr += strg[k - 1][x - 1][y - 2];
                }
                if(x + 1 < n && y + 2 < n){
                    numr += strg[k - 1][x + 1][y + 2];
                }
                if(x + 1 < n && y - 2 < n){
                    numr += strg[k - 1][x + 1][y - 2];
                }
                if(x + 2 < n && y + 1 < n){
                    numr += strg[k - 1][x + 2][y + 1];
                }
                if(x + 2 < n && y - 1 >= 0){
                    numr += strg[k - 1][x + 2][y - 1];
                }
                
                // cout << numr << endl;
                double mult = (1.0)/(8.0);
                strg[k][x][y] = mult * numr;
                // cout << strg[k][x][y] << " ";
            }
        }
    }

    return strg[k][x][y];
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--){
	    int n, x, y, k;
	    cin >> n >> x >> y >> k;
	    
	    cout << fixed << setprecision(6) << knightProbability(n, x, y, k) << endl;
	}
	return 0;
}