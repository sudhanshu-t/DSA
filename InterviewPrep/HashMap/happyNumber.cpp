#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;
// This is a functional problem. You have to complete this function.
// It takes as input a number n. It should return true if the number is
// happy, else should return false.
int giveSquare(int n){
    int sq = 0;
    while(n != 0){
        int d = n / 10;
        int r = n % 10;
        sq += r*r;
        n = d;
    }
    return sq;
}

bool isHappy(int n) {
    // write your code here.
    unordered_set<int> set;
    set.insert(n);

    while(n != 1){
        n = giveSquare(n);
        // cout << n << endl;

        if(set.find(n) != set.end()){
            return false;
        } else {
            set.insert(n);
        }
    }

    return true;
}

int main(int argc,char** argv) {
    int N;
    cin>>N;

    if (isHappy(N)) {
        cout<<"Happy"<<endl;
    } else {
        cout<<"Not Happy"<<endl;
    }
}