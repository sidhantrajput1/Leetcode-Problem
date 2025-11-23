class Solution {
public:
    int dp[100];
    int helper(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int take = nums[i] + helper(nums, i + 2);
        int not_take = helper(nums, i + 1);

        return dp[i] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return helper(nums, 0);
    }
};