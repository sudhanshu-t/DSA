#include <iostream>
#include <vector>

using namespace std;
// int sp = 0;
    // int ep = 1;

    // int i = 0;
    // while(sp != ep){
    //     if(o[i] + s - d[i] >= 0){
    //         ep = ((ep + 1) % d.size()) - 1;
    //     } else {
    //         sp = ((ep + 1) % d.size()) - 1;
    //         ep = ((ep + 1) % d.size()) - 1;
    //     }
    //     i++;
    // }

    // return sp;

int petrol_pumps(vector<int>& o, vector<int>& d){
    int i = 0; int j = 0; int spare = 0;

    while(i < d.size()){
        if(spare + o[j] >= d[j]){
            spare = spare + o[j] - d[j];
            j = (j + 1) % d.size();

            if(j == i){
                return j;
            }
        } else {
            if(j < i){
                return -1;
            } else {
                spare = 0;
                i = (j + 1) % d.size();
                j = i;
            }
        }
    }+
}

int main(int argc, char** argv){
    vector<int> o = {6,4,8,2,3,3,1,7,2};
    vector<int> d = {5,5,2,4,4,6,2,7,1};
    vector<int> o2 = {5};
    vector<int> d2 = {6};

    cout << petrol_pumps(o2, d2) << endl;    
}