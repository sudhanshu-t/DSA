#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool pairsum(vector<int>& arr, int k){
    unordered_map<int, int> map;

    for(int val : arr){
        map[val % k]++;
    }

    // if(map[0] % 2 != 0){
    //     return false;
    // }

    for(auto itr = map.begin(); itr != map.end(); itr++){
        cout << itr->first << " " << itr->second << endl;
    }

    for(auto itr = map.begin(); itr != map.end(); itr++){
        if(map[itr->first] != map[k - itr->first]){
            cout << itr->first << " " << k - itr->first << endl;
            return false;
        } else {
            map.erase(itr->first);
            map.erase(k - itr->first);
        }
    }

    return false;
}

int main(int argc, char** argv){
    vector<int> arr = {11,3,8,9,12,7,4,14,16,20,27,21,25,0,28,29,10,17,19,35};

    cout << pairsum(arr, 7) << endl;
}