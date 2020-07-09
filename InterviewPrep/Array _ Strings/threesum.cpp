#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input an array
// It should return an required output
vector<vector<int> > threeSum(vector<int>& nums) {
    //write your code here
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < nums.size(); i++){
        int left = i+1;
        int right = nums.size() - 1;

        int tar = nums[i];
        tar *= -1;
        while(left <= right){
            if(nums[left] + nums[right] > tar){
                while(nums[right-1] == nums[right]){
                    right--;
                }
                right--;
            }
            else if (nums[left] + nums[right] < tar){
                while(nums[left+1] == nums[left]){
                    left++;
                }
                left++;
            }
            else {
                vector<int> temp (3);
                temp[0] = nums[i];
                temp[1] = nums[left];
                temp[2] = nums[right];

                res.push_back(temp);

                while(nums[left+1] == nums[left]){
                    left++;
                }
                left++;
            }
        }

        while(nums[i+1] == nums[i]){
            i++;
        }
    }

    return res;    
}


void display(vector<vector<int> >& v){
    cout<<"["; 
    for(int j=0;j<v.size();j++){
        cout<<"[";
        for(int i=0;i<v[j].size();i++){
            cout<<v[j][i];
            if(i!=v[j].size()-1){
                cout<<", ";
            }
        }
        if(j!=v.size()-1)
            cout<<"], ";
        else
        {
            cout<<"]";
        }
        
    }
    cout<<"]";
}
int main(int argc,char** argv){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int> >res=threeSum(nums);
    display(res);

}