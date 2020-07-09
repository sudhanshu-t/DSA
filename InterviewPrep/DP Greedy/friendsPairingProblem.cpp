#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long int> strg (101, 0);

int M = 1000000007;

void fpp(){
    strg[1] = 1;
    strg[2] = 2;
    
    for(int i = 3; i <= 100; i++){
        strg[i] = (strg[i-1] % M + (((i-1) % M * strg[i-2] % M)) % M) % M;
    }
    
    for(int i = 1; i < 101; i++){
        cout << strg[i] << " ";
    }
    
    cout << endl;
}

// O(1) Space approach gfg

int main() {
	int t;
	cin >> t;
	
	fpp();
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    cout << strg[n] << endl;
	}
	return 0;
}