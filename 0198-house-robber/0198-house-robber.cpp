class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int i) {
        if (i >= nums.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int loot = nums[i] + helper(nums, i +2);
        int no_loot = 0 + helper(nums, i + 1);

        return dp[i] = max(loot, no_loot);
    }
    int rob(vector<int>& nums) {
        // clear garbage value
        dp.clear();
        dp.resize(105, -1); // 1 <= nums.length <= 100
        return helper(nums, 0);
    }
};