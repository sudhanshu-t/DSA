#include<iostream>
#include<vector>
using namespace std;

// This is a functional problem. You have to complete this function.
// It takes as input a String S and an integer array shifts.
// It should return the final string after all the shifts are applied.
string shiftingLetters(string &S, vector<int> &shifts) {
    // write your code here. 
    int sum = 0;
    for(int i = shifts.size() - 1; i >= 0; i--){
        shifts[i] %= 26;
        int safe = shifts[i];
        shifts[i] += sum;
        sum += safe;
    }

    string res;

    for(int i = 0; i < S.size(); i++){
        int p = (S[i] - 'a' + shifts[i]) % 26;
        char ch = p + 'a';

        res += ch;
    }
    return res;
}

int main(int argc, char** argv){
    string s;
    cin>>s;
    int N;
    cin>>N;

    vector<int> shifts(N);

    for (int i = 0; i < N; i++) {
        cin>>shifts[i];
    }

    cout<<shiftingLetters(s, shifts);
}