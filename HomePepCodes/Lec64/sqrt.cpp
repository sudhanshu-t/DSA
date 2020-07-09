#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>* oa = NULL;
vector<int>* sa = NULL;
int sob;
int nob;

void build(vector<int>& arr){
    // oa = new vector<int>(arr.size());

    oa = &arr;

    nob = int(sqrt(arr.size()));
    sob = nob;

    sa = new vector<int>(nob);
    
    for(int i = 0; i < oa->size(); i++){
        int bi = i / sob;
        (*sa)[bi] += (*oa)[i];
    }
    // cout << endl;

    for(int i = 0; i < sa->size(); i++){
        cout << sa->at(i) << " ";
    }
    cout << endl;
}

void update(int idx, int val){
    int old = (*oa)[idx];

    (*oa)[idx] = val;
    int delta = val - old;

    int bi = idx / sob;
    (*sa)[bi] += delta;
}

int query(int l, int r){
    int sum = 0;

    int lbi = l/sob;
    int rbi = r/sob;

    for(int i = l; i/sob == lbi; i++){
        sum += (*oa)[i];
    }

    for(int i = lbi + 1; i < rbi; i++){
        sum += (*sa)[i];
    }

    for(int i = r; i/sob == rbi; i++){
        sum += (*oa)[i];
    }

    return sum;
}

int main(int argc, char** argv){
    vector<int> arr (49);
    for(int i = 0; i < 49; i++){
        arr[i] = i;
    }

    build(arr);

    cout << query(10, 20) << endl;
    cout << query(24, 43) << endl;

    update(15, 10000);

    cout << query(10, 20) << endl;
    cout << query(24, 43) << endl;
}