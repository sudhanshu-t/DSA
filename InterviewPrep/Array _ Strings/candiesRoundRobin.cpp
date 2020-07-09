#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int candiesLeft, children;
    cin >> candiesLeft >> children;

    int* arr = new int[children];

    while(candiesLeft > 0){
        for(int i = 0; i < children; i++){
            if(candiesLeft >= i+1){
                arr[i] += i+1;
                candiesLeft -= i+1;
            } else {
                arr[i] += candiesLeft;
                candiesLeft = 0;
            }
        }
    }

    for(int i = 0; i < children; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}