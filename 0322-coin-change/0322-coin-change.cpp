class Solution {
public:
    vector<int> dp;
 
    Solution() {
        dp.resize(1000006, -1);
    }

    int helper(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int result = INT_MAX;
        for (int coin : coins) {
            int subAns = helper(coins, amount - coin);
            if (subAns != INT_MAX)
                result = min(result, 1 + subAns);
        }

        return dp[amount] = result;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = helper(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};