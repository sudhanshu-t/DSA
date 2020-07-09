#include <iostream>
#include <string>
#include <stack>

using namespace std;

void pattern_di(string s){
    stack<int> st;

    int count = 1;
    for(int i = 0; i <= s.size(); i++){
        char ch = s[i];
        st.push(count++);

        if(ch != 'd'){
            while(st.size() != 0){
                cout << st.top() << " ";
                st.pop();
            }
        }
    }

    cout << endl;

    return;
}

int main(int argc, char** argv){
    pattern_di("iddiid");
}