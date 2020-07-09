#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int countSub(vector<int>& v){
    int count = 0;
    unordered_map<int, int> map;
    
    int i = -1; int j = 0;
    
    while(j < v.size()){
        if(map.find(v[j]) == map.end()){
            map[v[j]]++;
            count++;
        } else {
            while(i < j){
                i++;
                
                if(i != j){
                    map[v[i]]--;

                    if(map[v[i]] == 0){
                        map.erase(v[i]);
                        if(v[i] != v[j]){
                            count++;
                            break;
                        }
                    }

                    
                } else {
                    if(map.find(v[j]) == map.end())
                        map[v[j]]++;
                }
            }
        }
        
        j++;
    }
    
    return count;
}

int countSubarray(vector<int>& arr){
    unordered_set<int> set;
    
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(set.find(arr[i]) == set.end()){
            count += set.size() + 1;
            set.insert(arr[i]);
        } else {
            cout << "Repeat : " << arr[i] << endl;
        }
    }
    
    // cout << count << endl;
    
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; 
    cin >> n;
    
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    // cout << countSub(arr) << endl;
    
    cout << countSubarray(arr) << endl;
    
    return 0;
}
