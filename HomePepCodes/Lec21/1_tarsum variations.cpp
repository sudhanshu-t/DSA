#include <iostream>
#include <vector>
#include <string>

using namespace std;

void tarsum1(int arr[], int n, int sp, int sum, string asf){
    if(sp == n){
        if(sum == 0){
            cout << asf << endl;
        }

        return;
    }
    
    tarsum1(arr, n, sp+1, sum-arr[sp], asf + to_string(arr[sp]) + " ");
    tarsum1(arr, n, sp+1, sum, asf);
}

void tarsum2(int arr[], int n, int sp, int sum, vector<int>& asf){
    if(sp == n){
        if(sum == 0){
            for(int i = 0; i < asf.size(); i++){
                cout << asf[i] << " ";
            }
            cout << endl;
        }

        return;
    }

    asf.push_back(arr[sp]);
    tarsum2(arr, n, sp+1, sum-arr[sp], asf);
    asf.pop_back();

    tarsum2(arr, n, sp+1, sum, asf);
}

int main(int argc, char** argv){
    int arr[] = {10,20,30,40,50,60,70};

    tarsum1(arr, 7, 0, 70, "");

    vector<int> kv;
    tarsum2(arr, 7, 0, 70, kv);
}