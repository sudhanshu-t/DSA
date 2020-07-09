#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

    // This is a functional problem. Only this function has to be written.
    // This function takes as input the head of the linked list.
    // It should return the head of the modified list.

void customerSolution(vector<int> &arr, int k)
{
    unordered_map<int, int> map;
    for(int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
    }

    int mymax = INT_MIN;
    for(auto itr : map){
        mymax = max(mymax, itr.second);
    }

    // cout << mymax << endl;

    if(mymax / 2 > k){
        cout << 0 << endl;
        return;
    }

    cout << 1 << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    
    customerSolution(arr,k);
    cout<<endl;
}

int main()
{
    solve();
    return 0;
}