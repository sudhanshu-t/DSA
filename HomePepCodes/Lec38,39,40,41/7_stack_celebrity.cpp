#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<bool>>& data){
    stack<int> st;

    for(int i = 0; i < data.size(); i++){
        st.push(i);
    }

    while(st.size() > 1){
        int one = st.top(); st.pop();
        int two = st.top(); st.pop();

        if(data[one][two]){
            st.push(two);
        } else if(data[two][one]){
            st.push(one);
        }
    }

    int ci = st.top();

    for(int i = 0; i < data.size(); i++){
        if(i != ci){
            if(data[ci][i] == true || data[i][ci] == false){
                return -1;
            }
        }
    }

    return ci;
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