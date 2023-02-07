#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums);
        int length = k%nums.size();
        //cout<<"length: "<<length<<"\n";
        //int j = 0;
        for(auto i = 0; i < nums.size();i++){
            if(-length+i<0)
                ans[i] = nums[nums.size()-length+i];
            else
                ans[i]=nums[-length+i];
        }            
        nums.assign(ans.begin(), ans.end());

    }
};

int main(){

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
     Solution ob;
     int buchang;
     cin>>buchang;
     ob.rotate(nums, buchang);
    cout<<"nums.size()="<<nums.size()<<endl;

    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
