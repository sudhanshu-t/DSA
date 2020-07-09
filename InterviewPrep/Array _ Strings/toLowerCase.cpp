#include<iostream>
#include<vector>
using namespace std;

string toLowerCase(string &a) {
    for(int i = 0; i < a.size(); i++){
        if(a[i] >= 65 && a[i] <= 90){
            a[i] = a[i] + 32;
        }
    }

    return a;
}


int main(int argc,char** argv){
    string a;
    cin>>a;
    cout<<toLowerCase(a)<<endl;
}