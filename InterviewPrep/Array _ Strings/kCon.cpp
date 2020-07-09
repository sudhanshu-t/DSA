#include <bits/stdc++.h>
using namespace std;

long long int kadane(long long int*& arr, int size){
    long long int lsum = arr[0];
    long long int gsum = arr[0];
    int lst = 0;
    int lend = 0;
    int gst = 0;
    int gend = 0;
    
    for(int i = 1; i < size; i++){
        if(lsum + arr[i] > arr[i]){
            lsum += arr[i];
            lend = i;
        } else {
            lsum = arr[i];
            lst = i;
            lend = i;
        }
        
        if(lsum > gsum){
            gsum = lsum;
            gst = lst;
            gend = lend;
        }
    }
    
    return gsum;
}

long long int kCon(long long int* arr, int n, int k){
    if(k < 1){
        return 0;
    }
    
    long long int sumSingle = kadane(arr, n);
    
    if(k == 1){
        return sumSingle;
    }
    
    long long pref = 0, suff = 0, p = 0, s = 0; // 2A sum is max suffix sum + max prefix sum
    
    for(int i = 0; i < n; i++){
        p += arr[i];
        s += arr[n - i - 1];
        
        pref = max(pref, p);
        suff = max(suff, s);
    }
    
    int sum = accumulate(arr, arr + n, 0ll);
    
    if(sum > 0){
        return pref + suff + (k - 2) * sum;
    } else {
        return max(pref + suff, sumSingle);
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    int n; int k;
	    cin >> n >> k;
	    
	    long long int* arr = new long long int[n];
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    cout << kCon(arr, n, k) << endl;
        delete arr;
	}
	
	return 0;
}