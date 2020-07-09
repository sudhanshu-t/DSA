#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

// ------------------------------------------------------
bool checkAP(vector<int> &arr)
{
    // write your code here
    int mymin = INT_MAX;
    int mymax = INT_MIN;

    for(int i = 0; i < arr.size(); i++){
        mymin = min(mymin, arr[i]);
        mymax = max(mymax, arr[i]);
    }

    if((mymax - mymin) % (arr.size() - 1) == 0){
        return true;

    return false;
}
// ------------------------------------------------------

// Do not change the main Method
int main()
{
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    if (checkAP(num))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}