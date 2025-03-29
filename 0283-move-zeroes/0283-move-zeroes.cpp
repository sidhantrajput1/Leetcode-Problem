class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        
        for (int ele : nums) {
            if (ele != 0) nums[idx++] = ele;
        }
        
        while (idx < nums.size()) nums[idx++] = 0;
    }
};