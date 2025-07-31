class Solution {
public:
    int totalSum; // total Sum 
    int solve(vector<int>& nums, int target, int i, int currSum, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (currSum == target) return 1;
            else return 0;
        }

        if (dp[i][currSum + totalSum] != -1) return dp[i][currSum + totalSum];

        int plus = solve(nums, target, i + 1, currSum + nums[i], dp);
        int minus = solve(nums, target, i + 1, currSum - nums[i], dp);

        return dp[i][currSum + totalSum] = plus + minus;
    } 
    int findTargetSumWays(vector<int>& nums, int target) {

        for (int num : nums) totalSum += num;
        
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2*totalSum+1, -1));

        return solve(nums, target, 0, 0, dp);

    }
};