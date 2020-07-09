#include<iostream>
#include<string>
#include <unordered_set>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2 strings.
// It should return a integer value.
int numJewelsInStones(string& J, string& S) {
    //Write your code here
    unordered_set<char> jewels;
    int count = 0;

    for(int i = 0; i < J.size(); i++){
        jewels.insert(J[i]);
    }

    for(int i = 0; i < S.size(); i++){
        if(jewels.find(S[i]) != jewels.end()){
            count++;
        }
    }

    return count;
}
int main(int argc,char** argv){
    string J,S;
    cin>>J;
    cin>>S;
    int res=numJewelsInStones(J, S);
        cout<<res;
}