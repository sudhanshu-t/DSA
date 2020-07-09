#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int lo, int hi){
    int i = lo, j = lo;
    int pivot = nums[hi];
    while(j <= hi){
        if(nums[j] <= pivot){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
        j++;
    }
    
    return i-1;
}

int ans;
void quicksort(vector<int>& nums, int lo, int hi, int k){
    if(lo < hi){
        int pi = partition(nums, lo, hi);
        if(pi == k-1){
            ans = nums[pi];
            cout << "Ans "<< ans << endl;
            return;
        }

        quicksort(nums, lo, pi-1, k);
        quicksort(nums, pi+1, hi, k);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    quicksort(nums, 0, nums.size()-1, k);
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,2,1,5,6,4};
    int n = arr.size();
    cout << (n|1) << endl;
    // cout << findKthLargest(arr, 4) << endl;
}