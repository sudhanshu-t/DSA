#include <iostream>
#include <string>
#include <vector>

#define vs vector<string>

using namespace std;

void perm_cc(int arr[], int n, int sum, string asf){
    if(sum < 0){
        return;
    }
    
    if(sum == 0){
        cout << asf << endl;
    }
    
    for(int i = 0; i < n; i++){
        perm_cc(arr, n, sum-arr[i], asf + to_string(arr[i]));
    }
}

void comb_cc(int arr[], int n, int luci, int sum, string asf){
    if(sum < 0){
        return;
    }
    
    if(sum == 0){
        cout << asf << endl;
    }
    
    for(int i = luci; i < n; i++){
        comb_cc(arr, n, i, sum-arr[i], asf + to_string(arr[i]));
    }
}

// vs* get_comb_cc(int arr[], int n, int )

void comb_cc1(int arr[], int sp, int sum, string asf){
    if(sum < 0){
        return;
    }
    
    if(sum == 0){
        cout << asf << endl;
        return;
    }

    // 2 comes in the combination
    comb_cc1(arr, sp, sum - arr[sp], asf + to_string(arr[sp]));

    // 2 doesn't comes in the combi
    comb_cc1(arr, sp+1, sum, asf);
}

int main(int argc, char** argv){
    int arr[] = {2,3,4,5};

    // perm_cc(arr, 4, 7, "");
    // comb_cc(arr, 4, 0, 7, "");

    comb_cc1(arr, 0, 7, "");
}