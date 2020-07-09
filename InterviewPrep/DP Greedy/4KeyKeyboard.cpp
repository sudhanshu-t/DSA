#include <iostream>
#include <climits>
#include <vector>

using namespace std;

vector<int> strg (76, 0);

int fourKey(){
    for(int i = 1; i <= 5; i++){
        strg[i] = i;
    }
    
    for(int i = 6; i < 76; i++){
        int myMax = max(2*strg[i-3], max(3*strg[i-4], 4*strg[i-5]));
        
        strg[i] = myMax;
    }
}

int main() {
    int t;
    cin >> t;
    
    fourKey();
    
    while(t--){
        int n;
        cin >> n;
        
        cout << strg[n] << endl;
    }

	return 0;
}