#include <iostream>
#include <vector>

using namespace std;

int kadane(int arr[], int n, int& start, int& end){
    int lsum = 0, gsum = 0, lst = 0, lend = 0, gend = 0, gst = 0;

    for(int i = 0; i < n; i++){
        if(lsum + arr[i] > arr[i])
        {
            lend = i;
            lsum += arr[i];
        } 
        else
        {
            lst = i;
            lend = i;
            lsum = arr[i];
        }
        
        if(lsum > gsum)
        {
            gst = lst;
            gend = lend;
            gsum = lsum;
        }
    }

    start = gst;
    end = gend;

    return gsum;
}

int row = 4;
int col = 5;

void find_submatrix_max_sum(int M[][col]){
    int start, end, final_left, final_right, final_top, final_bottom;
    int left, right;

    // for(int i = 0; i < )
}

int main(int argc, char** argv){
    // int arr[] = {1,-12,3,-1,3,5,1,3};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // int start = 0, end = 0;
    // int sum = kadane(arr, n, start, end);

    // cout << sum << endl << start << " " << end << endl;

    int M[row][col] = {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};  
  
    find_submatrix_max_sum(M);
}