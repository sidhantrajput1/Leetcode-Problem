class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 2;
        int n = nums.size();
        if(nums.size() <= 2) {
            return nums.size();
        }


        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[idx-2]) {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};