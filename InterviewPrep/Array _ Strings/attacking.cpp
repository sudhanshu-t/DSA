#include <iostream>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int count = 0;

    int st = 0;
    int end = 0;

    for(int i = 0; i < timeSeries.size(); i++){
        if(timeSeries[i] <= end){
            end = timeSeries[i] + duration;
        } else {
            count += end - st;
            st = timeSeries[i];
            end = timeSeries[i] + duration;
        }
    }

    count += end - st;
    return count;
}

int main(int argc,char** argv){
    int n;
    cin>>n;
    int k ;
    cin>>k;
    vector<int> timeseries(n);
    for (int i = 0; i < n; i++) {
        cin>>timeseries[i];
    }
    cout<<findPoisonedDuration(timeseries, k)<<endl;
}