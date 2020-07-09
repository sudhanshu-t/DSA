// Celebrity problem using left right approach

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int celebrity(vector<vector<bool>>& data){
    vector<int> v;

    for(int i = 0; i < data.size(); i++){
        v.push_back(i);
    }

    int left = 0; int right = v.size() - 1;

    while(left < right){
        if(data[left][right]){
            left++;
        } else if(data[right][left]){
            right--;
        }
    }

    for(int i = 0; i < data.size(); i++){
        if(i != left && (data[left][i] == true || data[i][left] == false)){
            return -1;
        }
    }

    return left;
}

int main(int argc, char** argv){
    vector<vector<bool>> data = {
        {false, false, true, false, true, true},
        {true, false, true, true, true, true},
        {true, false, false, true, true, false},
        {false, false, false, false, true, false},
        {false, false, false, false, true, false},
        {true, false, true, true, true, false}
    };

    cout << celebrity(data) << endl;
}