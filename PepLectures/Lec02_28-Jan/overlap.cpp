#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int s1, e1, s2, e2;

    cin>>s1>>e1>>s2>>e2;

    // Case 1: e1 is in e2
    if(s1>=s2 && e1<=e2){
        cout<<"E1 is in E2"<<endl;
    }

    // Case 2: e2 is in e1
    else if(s2>=s1 && e2<=e1){
        cout<<"E2 is in E1"<<endl;
    }

    // Case 3: No Overlap
    else if(e1<s2 || e2<s1){
        cout<<"No Overlap"<<endl;
    }

    // Case 4: Partial Overlap
    else {
        cout<<"Partial Overlap"<<endl;
    }
}