#include <iostream>
#include <vector>

using namespace std;

int kadane(vector<int>& arr){
    int lsum = 0;
    int lst = 0;
    int lend = 0;

    int gsum = 0;
    int gst = -1;
    int gend = -1;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > lsum + arr[i]){
            lst = i;
            lend = i;
            lsum = arr[i];
        } else {
            lend = i;
            lsum += arr[i];
        }

        if(lsum > gsum){
            gsum = lsum;
            gst = lst;
            gend = lend;
        }
    }

    return gsum;
}

int kConc(vector<int>& arr, int k){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }

    if(k == 1){
        return kadane(arr);
    }

    // Array doubling
    vector<int> doubleArr (arr);
    for(int i = 0; i < arr.size(); i++){
        doubleArr.push_back(arr[i]);
    }

    if(sum > 0){
        return kadane(doubleArr) + (k-2) * sum;
    } else {
        return kadane(doubleArr);
    }
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> arr (n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        cout << kConc(arr, k) << endl;
    }
}