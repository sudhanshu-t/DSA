#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int n;
    cin >> n;

    int spaces = n / 2;
    int stars = 1;

    int var = 1;
    for(int r = 1; r <= n; r++){

        for(int i = 1; i <= spaces; i++){
            cout<<" ";
        }


        var = (r <= n/2)?r: n-r+1;

        for(int i = 1; i <= stars; i++){
            
            cout<<var;
            if(i <= stars/2){
                var++;
            }
            else{
                var--;
            }
        }

        if(r <= n / 2){
            spaces--;
            stars += 2;
        }
        else
        {
            spaces++;
            stars -= 2;
        }
        
        cout<<endl;
    }
}

// Reviewed