#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>* oa = NULL;
vector<int>* sa = NULL;
int nob;
int sob;

void build(vector<int>& arr){
    oa = &arr;
    
    int nob = int(sqrt(arr.size()));
    sob = nob;

    sa = new vector<int> (nob);

    for(int i = 0; i < arr.size(); i++){
        int bi = i / sob;

        (*sa)[bi] += arr[i];
    }

    for(int i = 0; i < sa->size(); i++){
        cout << (*sa)[i] << " ";
    }

    cout << endl;
}

void update(int idx, int val){
    (*sa)[idx/sob] += val - (*oa)[idx];
    (*oa)[idx] = val;
}

int query(int l, int r){
    int sum = 0;
    for(int i = l; i/sob == l/sob; i++){
        sum += (*oa)[i];
    }

    for(int i = l/sob + 1; i < r/sob; i++){
        sum += (*sa)[i];
    }

    for(int i = r; i/sob == r/sob; i--){
        sum += (*oa)[i];
    }

    return sum;
}

int main(){
    vector<int> arr (9);

    for(int i = 0; i < arr.size(); i++){
        arr[i] = i;
    }

    build(arr);

    cout << query(3, 7) << endl;

    update(4, 40);
    
    cout << query(3, 7) << endl;
}