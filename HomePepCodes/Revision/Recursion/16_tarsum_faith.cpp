#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>* tarsum(vector<int>& v, int idx, int sum){
    if(idx == v.size()){
        vector<vector<int>>* bres = new vector<vector<int>>();
        if(sum == 0){
            vector<int> kv;
            bres->push_back(kv);
        }

        return bres;
    }
    
    vector<vector<int>>* mres = new vector<vector<int>>();

    vector<vector<int>>* rres1 = tarsum(v, idx + 1, sum - v[idx]);
    vector<vector<int>>* rres2 = tarsum(v, idx + 1, sum);

    for(int i = 0; i < rres1->size(); i++){
        rres1->at(i).push_back(v[idx]);
        mres->push_back(rres1->at(i));
    }

    for(int i = 0; i < rres2->size(); i++){
        mres->push_back(rres2->at(i));
    }

    delete rres1;
    delete rres2;
    
    return mres;
}

int main(int argc, char** argv){
    vector<int> arr = {10,20,30,40,50,60};

    vector<vector<int>>* v = tarsum(arr, 0, 70);

    for(int i = 0; i < (*v).size(); i++){
        for(int j = 0; j < v->at(i).size(); j++){
            cout << v->at(i).at(j) << " ";
        }

        cout << endl;
    }
}