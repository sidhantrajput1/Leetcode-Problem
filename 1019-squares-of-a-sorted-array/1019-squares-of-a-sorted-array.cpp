class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> ans(nums.size());
        int st = 0;
        int end = nums.size() - 1;

        int ptr = nums.size() - 1;

        while (st < end) {
            int left = nums[st] * nums[st];
            int right = nums[end] * nums[end];

            if(left > right) {
                ans[ptr] = left;
                st++;
            } else {
                ans[ptr] = right;
                end--;
            }
            ptr--;
        }
        return ans;
    }
};