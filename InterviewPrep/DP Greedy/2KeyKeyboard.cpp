#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int factorisationRootN(int n){
        if(n == 0 || n == 1){
            return 0;
        }
        
        int sum = 0;
        while(n % 2 == 0){
            sum += 2;
            n = n / 2;
        }
        
        // cout << sum << endl;
        
        // By this time, n is odd, so skip 2 at a time
        for(int i = 3; i <= sqrt(n); i += 2){
            while(n % i == 0){
                sum += i;
                n = n / i;
            }
            
            // cout << sum << endl;
            
            if(n <= 1){
                break;
            }
        }
        
        // Handling the case when n is prime number greater than 2
        if(n > 2){
            sum += n;
        }
        
        return sum;
    }
    
    int minSteps(int n) {
        return factorisationRootN(n);
    }
};