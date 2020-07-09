#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display an array.
void display(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// This is a functional problem. You have to complete this function.
// It takes as input a 2D array
// It should return the min number of meeting rooms required.
int minMeetingRooms(vector<vector<int> > &intervals) {
    vector<int> start (intervals.size());
    vector<int> end (intervals.size());

    for(int i = 0; i < intervals.size(); i++){
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int count = 0;
    int i = 0, j = 0;
    int maxRoom = 0;

    while(i < start.size()){
        if(start[i] < end[j]){
            count++;
            maxRoom = max(maxRoom, count);
            i++;
        } else{
            count--;
            j++;
        }
    }

    return maxRoom;
}

int main(int argc, char** argv){
    int n;
    cin>>n;
    vector<vector<int> > intervals(n, vector<int> (2));
    // Input for intervals.
    for (int i = 0; i < n; i++) {
        cin>>intervals[i][0];
        cin>>intervals[i][1];
    }
    int r = minMeetingRooms(intervals);
    cout<<r;
}