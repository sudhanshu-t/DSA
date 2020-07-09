#include <iostream>
#include <vector>
using namespace std;

int game(vector<int>& arr){
    vector<vector<int>> strg (arr.size() + 1, vector<int> (arr.size() + 1, 0));
    
    for(int x = 1; x < strg.size(); x++){
        for(int i = 0, j = x; j < strg.size(); i++, j++){
            if(x == 1){
                strg[i][j] = arr[i];
                continue;
            }
            
            strg[i][j] = max(arr[i] + min(strg[i+1][j-1], strg[i+2][j]),
                             arr[j-1] + min(strg[i+1][j-1], strg[i][j-2]));
        }
    }
    
    // for(int i = 0; i < strg.size(); i++){
    //     for(int j = 0; j < strg[0].size(); j++){
    //         cout << strg[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return strg[0][strg.size() - 1];
}

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr (n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    cout << game(arr) << endl;
	}
	return 0;
}