#include <iostream>
#include <string>
#include <vector>

using namespace std;

// s.insert(s.begin() + i, key) -> to insert at ith position the value key
// ^^ Both for strings and vectors ^^

vector<vector<int>>* tarsum1(int arr[], int sum ,int sp, int n){
    if(sp == n){
        vector<vector<int>>* bres = new vector<vector<int>>();
        if(sum == 0){
            vector<int> kv;
            (*bres).push_back(kv);
        }

        return bres;
    }

    vector<vector<int>>* r1 = tarsum1(arr, sum - arr[sp], sp+1, n);
    vector<vector<int>>* r2 = tarsum1(arr, sum, sp+1, n);

    vector<vector<int>>* mres = new vector<vector<int>>();

    for(int i = 0; i < (*r1).size(); i++){
        (*r1)[i].push_back(arr[sp]);
        (*mres).push_back((*r1)[i]);
    }

    for(int i = 0; i < (*r2).size(); i++){
        (*mres).push_back((*r2)[i]);
    }

    delete r1;
    delete r2;

    return mres;
}

void tarsum2(int arr[], int sum, int sp, int n, string asf){
    if(sp == n){
        if(sum == 0)
            cout << asf << endl;
        return;
    }

    tarsum2(arr, sum-arr[sp], sp+1, n, asf + to_string(arr[sp]) + " ");
    tarsum2(arr, sum, sp+1, n, asf);
}

// Variation to show that we can't pushback or popback in a vector in a function call
void tarsum3(int arr[], int sum, int sp, int n, vector<int>& asf){
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
    tarsum3(arr, sum - arr[sp], sp + 1, n, asf);

    asf.pop_back();
    tarsum3(arr, sum, sp + 1, n, asf);
}

int main(int argc, char** argv){
    int arr[] = {10,20,30,40,50,60,70};
    // vector<vector<int>>* ans = tarsum1(arr, 70, 0, 7);

    // for(int i = 0; i < ans->size(); i++){
    //     for(int j = 0; j < (*ans)[i].size(); j++){
    //         cout << (*ans)[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // tarsum2(arr, 70, 0, 7, "");

    vector<int> kv;
    tarsum3(arr, 70, 0, 7, kv);
}