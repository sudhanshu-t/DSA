#include <iostream>

using namespace std;
int main(int argc, char** argv){
    int arr[100], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int lsum = arr[0], gsum = arr[0], lst = 0, gst = 0, lend = 0, gend = 0;

    for(int i = 1; i < n; i++){
        if(lsum + arr[i] > arr[i]){
            lend = i;
            lsum = lsum + arr[i];
        } else {
            lst = i;
            lend = i;
            lsum = arr[i];
        }

        if(lsum > gsum){
            gsum = lsum;
            gst = lst;
            gend = lend;
        }
    }

    cout << "Max Sum is: " << gsum << " - (" << gst << ", " << gend << ")" << endl;

    return 0;
}