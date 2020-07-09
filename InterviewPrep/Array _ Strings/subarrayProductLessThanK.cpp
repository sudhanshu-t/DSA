#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written
// This function takes as input an array and integer k
// It should return the required output

int numSubarrayProductLessThanK(vector<int> nums, int k) {
    int i = -1;
    int j = 0;

    int prod = 1;
    int count = 0;
    while(j < nums.size()){
        prod *= nums[j];

        if(prod < k){
            count += j - i;
        } else {
            while(prod >= k && i < j){
                i++;
                prod /= nums[i];
            }

            count += j - i;
        }

        j++;
    }

    return count;
}
int main(int argc,char**argv){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }   
    int k;
    cin>>k;

    cout<<numSubarrayProductLessThanK(v, k)<<endl;
    
}