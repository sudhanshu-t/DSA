#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>>* tarsum(int a[], int tar, int sp, int n){
    // if(tar <= 0 && n != 0){
    //     vector <vector <int>> bres;
    //     return bres;
    // }

    // if(n == 0){
    //     vector <vector <int>> bres;
    //     return bres;
    // }

    // vector <vector <int>> mres;

    // for(int i = 0; i < n; i++){
    //     vector <vector <int>> vvi = tarsum(a, tar - a[i], n-1);
    //     for(int j = 0; j < vvi.size(); j++){
    //         vvi[j].push_back(a[i]);
    //     }

    //     for(int j = 0; j < vvi.size(); j++){
    //         mres.push_back(vvi[j]);
    //     }
    // }

    // return mres;

    if(sp == n){
        vector <vector <int>>* bres = new vector <vector <int>>();

        if(tar == 0){
            vector <int> kv;
            bres->push_back(kv);
        }

        return bres;
    }

    vector <vector <int>>* rr1 = tarsum (a, tar - a[sp], sp+1, n);
    vector <vector <int>>* rr2 = tarsum (a, tar, sp+1, n);

    vector <vector <int>>* mres = new vector <vector <int>>();

    for(int i = 0; i < rr1->size(); i++){
        (*rr1)[i].push_back(a[sp]);

        mres->push_back((*rr1)[i]);
    }

    for(int i = 0; i < rr2->size(); i++){
        mres->push_back((*rr2)[i]);
    }

    delete rr1;
    delete rr2;

    return mres;
}

int main(int argc, char** argv){
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    vector <vector <int>>* ans = tarsum(a, 70, 0, 7);

    // cout << ans.size() << endl;

    for(int i = 0; i < ans->size(); i++){
        for(int j = 0; j < (*ans)[i].size(); j++){
            cout << (*ans)[i][j] << " ";
        }

        cout << endl;
    }
}