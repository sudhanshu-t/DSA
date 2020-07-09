#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n;
    bool prime = true;
    cin>>n;

    // Implementation 1
        // After root(n), the factors start repeating themselves
    
    // for(int i = 2; i <= sqrt(n); i++){
    //     if(n%2 == 0){
    //         prime =false;
    //         break;
    //     }
    // }

    // if(prime){
    //     cout<<"Prime"<<endl;
    // } else{
    //     cout<<"Non-Prime"<<endl;
    // }


    //Implementation 2

    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            cout<<"Non-Prime"<<endl;
            return 0;
        }
    }

    cout<<"Prime"<<endl;

    return 0;
}