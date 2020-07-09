#include<iostream>
using namespace std;

int main(int argc, char** argv){
    // int a;
    // int b;
    // int c;
    // int d;
    // int e;
    // int f;
    // cin>> a >> b >> c >> d >> e >> f;

    int arr[100];
    int n; 
    cin >> n;

    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    
        max = (arr[i] >= max) ? arr[i] : max;
    }

    for(int i = 0; i < max; i++){
        for(int j = 0; j < n; j++){
            if(i < max - arr[j]){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}