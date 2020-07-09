#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int ceil(vector<int>& arr, int factor){
    int c = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > factor && arr[i] < c){
            c = arr[i];
        }
    }
    
    return c;
}

int kSmallest(vector<int>& arr, int k){
    int factor = INT_MIN;
    
    for(int i = 0; i < k; i++){
        factor = ceil(arr, factor);
    }
    
    return factor;
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    
	    vector<int> arr (n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    int k;
	    cin >> k;
	    
	    cout << kSmallest(arr, k) << endl;
	}
}