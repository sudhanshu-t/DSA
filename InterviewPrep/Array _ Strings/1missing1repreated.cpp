#include <iostream>
#include <vector>

using namespace std;

vector<int> fun(vector<int>& A){
    long long int sumActual = 0;
    long long int sumActualSq = 0;
    int n = A.size();

    for(int i = 0; i < n; i++){
        sumActual += A[i];
        sumActualSq += (A[i] * A[i]);
    }

    long long int sum = n * (n+1) / 2;
    long long int sumSq = n * (n + 1) * (2*n + 1) / 6;

    int a, b;

    int diffAB = (int) (sumActual - sum);
    int sumAB = (int) ((sumActualSq - sumSq) / diffAB);

    a = (sumAB + diffAB) / 2;
    b = (sumAB - diffAB) / 2;

    vector<int> res(2);
    res[0] = a;
    res[1] = b;

    // cout << sum << endl;
    // cout << sumActual << endl;

    return res;
}

int main(int argc, char** argv){
    vector<int> arr = {3,1,2,3,5};
    vector<int> res = fun(arr);
    cout << res[0] << " " << res[1] << endl;
}