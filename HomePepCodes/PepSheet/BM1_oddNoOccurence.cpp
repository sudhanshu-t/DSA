#include <iostream>
using namespace std;

int main() {
	//code
	
	int t, a[1000000];
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    int odd = 0;
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    
	    for(int i = 0; i < n; i++){
	        odd ^= a[i];
	    }
	    
	    cout << odd << endl;
	}
	return 0;
}