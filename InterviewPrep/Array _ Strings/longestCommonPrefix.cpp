#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

string longestCommonPrefix(vector<string>& arr, int myMax){
    string res = "";
    bool done = false;
    for(int i = 0; i < myMax; i++){
        char ch = arr[0][i];
        for(int j = 1; j < arr.size(); j++){
            if(arr[j][i] != ch){
                done = true;
                break;
            }
        }
        
        if(!done)
            res += ch;
        else
        {
            break;
        }
        
    }
    
    return res;
    
}

int main() {
	//code
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<string> arr (n);
	    int myMax = INT_MAX;
	    for(int i = 0; i < n; i++){
	        string str;
	        cin >> str;
	        arr[i] = str;
            // cout << str.size() << endl;
	        if(str.size() < myMax){
                myMax = str.size();
            }
	    }
	    
        if(n == 1){
            cout << arr[0] << endl;
            continue;
        }

        if(longestCommonPrefix(arr, myMax).size() != 0){
            cout << longestCommonPrefix(arr, myMax) << endl;
        } else {
            cout << -1 << endl;
        }
	}
	return 0;
}