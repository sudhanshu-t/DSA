#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// int sum(const vector<int>& arr){
//     unordered_set<int> fmap;
//     int sum = 0;

//     int i = 0;
//     int j = 0;
//     // cout << s.size() << endl;

//     while(i < arr.size() && j < arr.size()){
//         // cout << "Andar" << endl;
//         if(fmap.find(arr[j]) != fmap.end()){
//             j--;
//             int l = j - i + 1;
//             for(int k = 1; k <= l; k++){
//                 sum += k * (l - k + 1);
//             }


//             // cout << "Sum till now " << sum << endl;

//             fmap.erase(arr[i]);

//             i++;
//             j++;
//             // while(true){}
//         } else {
//             fmap.insert(arr[j]);
//             // cout << "Inserted " << s[j] << endl;
//             j++;
//         }
//     }

//     j--;
//     int l = j - i + 1;
//     for(int k = 1; k <= l; k++){
//         sum += k * (l - k + 1);
//     }

//     return sum;
// }

int sum(const vector<int>& arr){
    int i = 0;
    int j = 0;
    int sum = 0;

    unordered_set<int> fset;
    while(i < arr.size() && j < arr.size()){
        if(fset.find(arr[j]) == fset.end()){
            fset.insert(arr[j]);
            j++;
        } else {
            j--;

            int l = j - i + 1;
            sum += l * (l + 1) / 2;

            fset.erase(arr[i]);
            i++;
            j++;
        }
    }

    j--;
    while(i <= j){
        int l = j - i + 1;
        sum += l * (l + 1) / 2;
        i++;
    }

    return sum;
}

int main(int argc, char** argv){
    // string s = "abbacdabbcdadcbabd";
    // cout << sum(s) << endl;
    
    int n;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << sum(arr) << endl;
}