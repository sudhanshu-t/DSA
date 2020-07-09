#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int>* stock_span(vector<int>& v){
    stack<int> st;
    vector<int>* res = new vector<int>();
    // vector<int> nge (v.size());

    // finding nge
    // for(int i = 0; i < v.size(); i++){
    //     int count = 1;
    //     while(st.size() > 0 && st.top() < v[i]){
    //         st.pop();
    //         count++;
    //     }

    //     st.push(v[i]);
    //     res->push_back(count);
    // }
    
    for(int i = 0; i < v.size(); i++){
        // int count = 1;
        while(st.size() > 0 && v[st.top()] < v[i]){
            st.pop();
            // count++;
        }

        int span = st.size() == 0 ? i + 1 : i - st.top();
        st.push(i);

        res->push_back(span);
    }

    return res;
}

int main(int argc, char** argv){
    vector<int> v = {4,1,2,7,9,6,5,3,8};

    vector<int>* res = stock_span(v);

    for(int i = 0; i < res->size(); i++){
        cout << res->at(i) << " ";
    }

    cout << endl;
}