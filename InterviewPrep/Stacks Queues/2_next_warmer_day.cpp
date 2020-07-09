#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int>* findWarmerTemp(vector<int> temp){
// Write your code here only
    vector<int>* ans = new vector<int>(temp.size());

    // for(int i = 0; i < temp.size(); i++){
    //     ans->push_back(0);
    // }

    // cout << ans->size() << endl;

    stack<int> st;

    for(int i = temp.size() - 1; i >= 0; i--){
        while(st.size() != 0 && temp[st.top()] < temp[i]){
            st.pop();
        }

        (*ans)[i] = (st.size() == 0) ? 0 : st.top() - i;
        st.push(i);
    }

    return ans;
}

// Dont make changes here
int main() {
    int n; cin >> n;
    vector<int> temp;

    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        temp.push_back(t);
    }

    vector<int>* ans = findWarmerTemp(temp);
    
    // cout << ans->size() << endl;
    for(int i = 0; i < ans->size(); i++){
        cout << ans->at(i) << endl;
    }
}