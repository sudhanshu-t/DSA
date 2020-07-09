#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;
    // This is a functional problem. You have to complete this function.
    // It takes as input an array A and a sum S.
    // You have to return the number of subarrays with sum S.

    int numSubarraysWithSum(vector<int> A, int S) {
        // write your code here.
        unordered_map<int, int> map;
        int presum = 0;

        int count = 0;

        map[0] = 1;
        for(int i = 0; i < A.size(); i++){
            presum += A[i];

            if(map.find(presum - S) != map.end()){
                count += map[presum - S];
            }

            map[presum]++;
        }

        return count;
    }

    int main(int args,char** argv) {
        // Taking input for the array.
        int N; cin>>N;
        vector<int> array(N,0);

        for (int i = 0; i < N; i++) {
            cin>>array[i];
        }

        // Taking input for sum.
        int sum;cin>>sum;

        cout<<(numSubarraysWithSum(array, sum));

    }