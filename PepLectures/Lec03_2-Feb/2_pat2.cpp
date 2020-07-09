#include<iostream>
using namespace std;

int main(int argc, char ** argv){
    int n, count = 1;
    cin >> n;

    for(int r = 1; r <= n; r++){
        for(int c = 1; c <= r; c++){
            cout<<count<<"\t";
            count++;
        }
        cout<<endl;
    }

    return 0;
}

// reviewed