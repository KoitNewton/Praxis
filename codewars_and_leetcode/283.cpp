class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int right = nums.size()-1;
        int left = right;
        while(left>=0){
            if(nums[left] == 0){
                for(int i=left;i<right;i++){
                    nums[i] = nums[i+1];
                }
                nums[right] = 0;
            }
            left--;
        }
    }
};

class Solution {
    public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int num : nums) {
            if (num != 0) {
                nums[index++] = num;
            }
        }
        for (int i = index; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};