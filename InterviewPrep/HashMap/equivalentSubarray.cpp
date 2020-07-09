#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array
// It should return an integer value.
int val(vector<int> &arr) {
    unordered_map<int, int> map;

    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    int size = map.size();
    map.clear();

    cout << size << endl;

    int i = -1; int j = 0;

    int count = 0;

    while(j < arr.size()){
        // acquire till k unique
        map[arr[j]]++;

        cout << arr[j] << " " << map[arr[j]] << endl;

        if(map.size() == size){
            count += arr.size() - j;

            // release till k-1 unique
            while(map.size() != size-1){
                i++;
                map[arr[i]]--;

                cout << "Removed " << arr[i] << " " << map[arr[i]] << endl;

                if(map[arr[i]] == 0){
                    map.erase(arr[i]);
                }

                if(map.size() == size){
                    count += arr.size() - j;
                }
            }
        }

        j++;
    }

    return count;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<int> arr;
    for(int  i=0;i<n;i++){
        int val; cin>>val;
        arr.push_back(val);
    }
    cout<<val(arr);
}