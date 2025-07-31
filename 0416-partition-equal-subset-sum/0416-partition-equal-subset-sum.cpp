class Solution {
public:
    // global dp table
    vector<vector<int>> dp;

    bool solve(vector<int>& nums, int idx, int target) {
        if (target == 0) return true;

        if (idx >= nums.size() || target < 0) return false;

        if (dp[idx][target] != -1) return dp[idx][target];

        bool take = solve(nums, idx+1, target - nums[idx]);
        bool not_take = solve(nums, idx+1, target);

        
        dp[idx][target] = take || not_take;
        return dp[idx][target];

    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;

        dp = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));

        // start from 0 index
        return solve(nums, 0, target); 
    }
};