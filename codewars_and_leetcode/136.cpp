#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};



int main(){
    vector<int> nums({1,1,3,3,5,5,7,8,8});
    Solution obj;
    int a=obj.singleNumber(nums);
    cout << a;
    return 0;


}
