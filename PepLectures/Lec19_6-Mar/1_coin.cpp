#include <iostream>
#include <string>
using namespace std;

void printcc_perm(int arr[], int n, int sum, string asf){
    if(sum == 0){
        cout << asf << endl;

        return;
    }

    for(int i = 0; i < n; i++){
        if(sum - arr[i] >= 0)
            printcc_perm(arr, n, sum - arr[i], asf + to_string(arr[i]));
    }  
}

void printcc_comb(int arr[], int luci, int n, int sum, string asf){
    if(sum == 0){
        cout << asf << endl;

        return;
    }

    for(int i = luci; i < n; i++){
        if(arr[i] <= sum){
            printcc_comb(arr, i, n, sum - arr[i], asf + to_string(arr[i]));
        }
    }
}

// Do using get approach 



int main(int argc, char** argv){
    int arr[] = {2,3,5};

    // printcc_perm(arr, 3, 7, "");
    printcc_comb(arr, 0, 3, 7, "");
}