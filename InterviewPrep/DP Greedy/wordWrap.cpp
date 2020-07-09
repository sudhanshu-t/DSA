#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int cube(int n){
    return n*n*n;
}

int wordWrap(vector<int>& arr, int len){
    vector<int> strg (arr.size());
    vector<int> lenSum (arr.size());
    strg[0] = cube(arr[0]);
    
    int sum = 0;
    for(int i = 0; i < lenSum.size(); i++){
        sum += arr[i];
        lenSum[i] = sum;
    }
    
    for(int i = 1; i < arr.size(); i++){
        int myMin = INT_MAX;
        for(int j = 0; j <= i; j++){
            int gap = i - j;
            
            int prev = (j - 1 >= 0) ? strg[j-1] : 0;
            int prevLen = (j - 1 >= 0) ? lenSum[j-1] : 0;
            
            if(lenSum[i] - prevLen + gap <= len){
                myMin = min(myMin, prev + cube(len - (lenSum[i] - prevLen + gap)));    
            }
        }
        
        strg[i] = myMin;
    }
    
    return strg[strg.size() - 1];
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
	    
	    int len;
	    cin >> len;
	    
	    cout << wordWrap(arr, len) << endl;
	}
	
	return 0;
}