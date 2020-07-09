#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool canReorder(int A[], int n) {
    unordered_map<int, int> map;
    sort(A, A + n);

    for(int i = 0; i < n; i++){
        // cout << A[i] << " ";
        map[A[i]]++;
    }

    // for(auto itr : map){
    //     // cout << itr.first << " " << itr.second << endl;
    // }

    // cout << endl;

    for(int i = 0; i < n; i++){
        if(A[i] == 0 && map.find(A[i]) != map.end()){
            if(map[A[i]] % 2 != 0){
                // cout << "1" << endl;
                return false;
            } else {
                map.erase(A[i]);
            }
        } else if(A[i] < 0 && map.find(A[i]) != map.end()){
            if(map.find(A[i] / 2) != map.end() && map[A[i] / 2] >= map[A[i]]){
                // cout << "Found" << endl;
                map[A[i] / 2] -= map[A[i]];
                if(map[A[i] / 2] == 0){
                    map.erase(A[i] / 2);
                }
                map.erase(A[i]);
            } else {
                // cout << "2" << A[i] << endl;
                return false;
            }
        } else if(map.find(A[i]) != map.end()){
            if(map.find(2*A[i]) != map.end() && map[2*A[i]] >= map[A[i]]){
                map[2*A[i]] -= map[A[i]];
                if(map[2*A[i]] == 0){
                    map.erase(2*A[i]);
                }
                map.erase(A[i]);
            } else {
                // cout << "3" << endl;
                return false;
            }
        }
    }

    if(map.size() != 0){
        return false;
    }

    return true;
}

int main(int argc, char** argv) {
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    if(canReorder(a, size) == 0){
        cout<<"false"<<endl;
    }else{
        cout<<"true"<<endl;
    }
}