#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector<int> nextLarger(vector<int> &data ){
    // TODO Write the solution here    
    stack<int> st;
    vector<int> res (data.size());

    for(int i = data.size() - 1; i >= 0; i--){
        while(st.size() > 0 && data[i] >= st.top()){
            st.pop();
        }

        res[i] = (st.size() != 0) ? st.top() : -1;
        st.push(data[i]);
    }

    return res;
}


int main()
{
//handled Input
    int n = 0;
    cin >> n;
    vector<int> data(n, 0);
    for(int i=0; i<n; i++)
    {   
        int a=0; 
        cin >> data[i];
    }
    //Function Call for solution 
    vector<int> res = nextLarger(data);

    // Output Print
    for(int i=0; i<res.size(); i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}