#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

void max_area_histogram(vector<int>& v){
    vector<int> lb (v.size(), 0);
    vector<int> rb (v.size(), 0);
    vector<int> area (v.size(), 0);

    stack<int> st;

    // Left boundaries
    for(int i = 0; i < v.size(); i++){
        while(st.size() > 0 && v[st.top()] > v[i]){
            st.pop();
        }

        lb[i] = st.size() == 0 ? -1 : st.top();
        st.push(i);
    }

    while(st.size() != 0){
        st.pop();
    }

    // Right boundaries
    for(int i = v.size() - 1; i >= 0; i--){
        while(st.size() > 0 && v[st.top()] > v[i]){
            st.pop();
        }

        rb[i] = st.size() > 0 ? st.top() : v.size();
        st.push(i);
    }

    // Calculating areas
    int max = INT_MIN;
    for(int i = 0; i < v.size(); i++){
        area[i] = (rb[i] - lb[i] - 1) * v[i];

        if(area[i] > max){
            max = area[i];
        }
    }

    cout << max << endl;
}

int main(int argc, char** argv){
    vector<int> v = {6,2,5,4,5,1,6};
    max_area_histogram(v);
}