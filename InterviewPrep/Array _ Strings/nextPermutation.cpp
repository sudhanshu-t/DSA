#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &num) {
    int len = num.size();
    int i,j;
    for(i = len - 2; i >= 0 ; i--)
        if(num[i] < num[i+1]) break;

    if (i == -1) {
        reverse(num.begin(), num.end());
        return;
    }

    for(j = len - 1; j > i; j--)
        if(num[j] > num[i]) break;

    swap(num[i], num[j]);
    reverse(num.begin() + i + 1, num.end());
    return;
}

void nextPermutation2(vector<int> &A) {
    
    int i, j;
    
    for(i = A.size() - 2; i >= 0; i--){
        if(A[i] < A[i+1]){
            break;
        }
    }
    
    if(i == -1){
        reverse(A.begin(), A.end());
        return;
    }
    
    for(j = A.size() - 1; j > i; j--){
        if(A[j] > A[i]){
            break;
        }
    }

    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;

    reverse(A.begin() + i + 1, A.end());
}

int main(int argc, char** argv){
    vector<int> A = {444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52};
    vector<int> B = {20,50,113};
    nextPermutation2(A);

    // next_permutation(A.begin(), A.end());


    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}