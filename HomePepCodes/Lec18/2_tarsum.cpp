#include <iostream>
#include <string>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

vvi* tarsum(vi& arr, int sum, int sp){
    if(sp == arr.size()){
        vvi* bres = new vvi();
        
        if(sum == 0){
            vi kv;
            bres->push_back(kv);
        }

        return bres;
    }
    
    vvi* mres = new vvi();

    vvi* r1 = tarsum(arr, sum-arr[sp], sp+1);
    vvi* r2 = tarsum(arr, sum, sp+1);

    for(int j = 0; j < (*r1).size(); j++){
        (*r1)[j].push_back(arr[sp]);
        mres->push_back((*r1)[j]);
    }

    for(int j = 0; j < (*r2).size(); j++){
        mres->push_back((*r2)[j]);
    }

    delete r1;
    delete r2;

    return mres;
}

int main(int argc, char** argv){
    vi arr = {10,20,30,40,50,60,70};

    vvi* res = tarsum(arr, 70, 0);
    for(int i = 0; i < res->size(); i++){
        for(int j = 0; j < (*res)[i].size(); j++){
            cout << (*res)[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}