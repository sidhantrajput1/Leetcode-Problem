class Solution {
public:
    int minCost(vector<int>& cost, int i, vector<int>& dp) {
        if (i <= 1) return cost[i];

        if (dp[i] != -1) return dp[i];

        int oneStep = minCost(cost, i - 1, dp);
        int twoStep = minCost(cost, i - 2, dp);

        return dp[i] = cost[i] + min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, -1);
        
        return min(minCost(cost, n-1, dp), minCost(cost, n - 2, dp));
    }
};