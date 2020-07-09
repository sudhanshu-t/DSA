#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int>* sliding_window(vector<int>& v, int k){
    vector<int>* res = new vector<int>();

    vector<int> nge (v.size(), 0);
    stack<int> st;

    for(int i = v.size() - 1; i >= 0; i--){
        while(st.size() > 0 && v[st.top()] < v[i]){
            st.pop();
        }

        nge[i] = st.size() > 0 ? st.top() : v.size();
        st.push(i);
    }

    int j = 0;
    for(int i = 0; i < v.size() - k + 1; i++){
        if(j < i){
            j = i;
        }

        while(nge[j] < i + k){
            j = nge[j];
        }

        res->push_back(v[j]);
    }

    return res;
}

int main(int argc, char** argv){
    vector<int> v = {4,1,2,7,9,6,5,3,8};
    vector<int>* res = sliding_window(v, 3);

    for(int i = 0; i < res->size(); i++){
        cout << (*res)[i] << " ";
    }

    cout << endl;
}