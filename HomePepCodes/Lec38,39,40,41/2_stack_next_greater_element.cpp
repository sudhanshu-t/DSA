#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// right to left (while finding nge on right)
void nge_1(vector<int>& v){
    stack<int> st;
    vector<int> nge (v.size(), 0);

    for(int i = v.size() - 1; i >= 0; i--){
        while(st.size() != 0 && st.top() < v[i]){
            st.pop();
        }

        nge[i] = st.size() == 0 ? -1 : st.top();
        st.push(v[i]);
    }

    for(int i = 0; i < nge.size(); i++){
        cout << nge[i] << " ";
    }

    cout << endl;
}

void nge_2(vector<int>& v){
    stack<int> st;
    vector<int> nge (v.size(), 0);

    for(int i = 0; i < v.size(); i++){
        while(st.size() > 0 && v[st.top()] < v[i]){
            nge[st.top()] = v[i];
            st.pop();
        }

        st.push(i);
    }

    while(st.size() != 0){
        nge[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < nge.size(); i++){
        cout << nge[i] << " ";
    }

    cout << endl;
}

int main(int argc, char** argv){
    vector<int> v = {4,1,2,7,9,6,5,3,8};
    nge_1(v);
    nge_2(v);
}