class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int loot = nums[i] + helper(nums, i + 2, dp);
        int no_loot = helper(nums, i + 1, dp);

        return dp[i] = max(loot, no_loot);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};