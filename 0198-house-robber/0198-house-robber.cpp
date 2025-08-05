class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 2], nums[n - 1]);

        for (int i = n - 3; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }

        return dp[0];
    }
    int rob(vector<int>& nums) {
        return helper(nums);
    }
};