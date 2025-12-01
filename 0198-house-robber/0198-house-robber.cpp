class Solution {
public:
    int n;
    int helper(vector<int>& nums, vector<int>& dp, int i) {
        if (i >= n) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        int loot = nums[i] + helper(nums, dp, i + 2);
        int no_loot = 0 + helper(nums, dp, i + 1);
        
        return dp[i] = max(loot, no_loot);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(105, -1);
        return helper(nums, dp, 0);
    }
};