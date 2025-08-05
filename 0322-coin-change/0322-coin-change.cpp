class Solution {
public:
    vector<int>*coin;
    vector<int> dp;
 
    Solution() {
        dp.resize(1000006, -1);
    }

    int helper(int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;

        if (dp[amount] != -1) return dp[amount];

        int result = INT_MAX;
        for (int i = 0; i < coin->size(); i++) {
            int subAns = helper(amount - (*coin)[i]);
            if (subAns != INT_MAX)
                result = min(result, 1 + subAns);
        }

        return dp[amount] = result;
    }
    // vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        // dp.clear();
        // dp.resize();
        coin = &coins;
        int ans = helper(amount);
        return ans == INT_MAX ? -1 : ans;
    }
};