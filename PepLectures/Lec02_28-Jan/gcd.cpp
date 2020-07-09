#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1>>n2;

    int div = n1;
    int divi = n2;
    
    int rem = divi % div;

    while(rem != 0){
        divi = div;
        div = rem;
        rem = divi % div;
    }

    cout<<div<<endl;
}