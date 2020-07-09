#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin>>n;

    int spaces = 2 * n - 3;
    int stars = 1;

    int var;
    for(int r = 1; r <= n; r++){
        var = 1;
        for(int i = 1; i <= stars; i++){
            cout<<var;
            var++;
        }

        for(int i = 1; i <= spaces; i++){
            cout<<" ";
        }

        var = (r == n)?n-1:r;
        stars = (r == n)? stars-1 : stars;

        for(int i = 1; i <= stars; i++){
            cout<<var;
            
            var--;
        }
        
        spaces -= 2;
        stars++;
        
        cout<<endl;
    }
}