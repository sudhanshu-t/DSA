#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// This is a functional problem. Only this function has to be written.
// This function takes as input a string and an integer k.
// It should return required integer value.
int countOfSubstringWithKOnes(string s, int K) 
{ 
    unordered_map<char, int> map;

    int presum = 0;
    map[0] = 1;
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        int ch = s[i] - '0';

        presum += ch;
        
        if(map.find(presum - K) != map.end()){
            count += map[presum - K];
        }
        map[presum]++;
    }

    return count;
} 
// -----------------------------------------------------

int main(int argc, char** argv){
    string s;
    cin>>s; 
    int K;
    cin>>K; 
        
    cout<<countOfSubstringWithKOnes(s, K);
}