#include<iostream>
#include<vector>
using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array of heights
// It should return required output.	  

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int mymax = 0;

    while(left < right){
        mymax = max(mymax, min(height[left], height[right]) * (right - left));

        // cout << left << " " << right << " " << mymax << endl;

        if(height[left] < height[right]){
            left++;
        } else if(height[right] < height[left]){
            right--;
        } else {
            left++;
            right--;
        }
    }

    return mymax;
}
//Don't make any changes here.
int main (int argc,char**argv){
    int n;
    cin>>n;
    vector<int> height(n);
    for (int i = 0; i < height.size(); i++) {
        cin>>height[i];
    }
    cout<<maxArea(height);

}