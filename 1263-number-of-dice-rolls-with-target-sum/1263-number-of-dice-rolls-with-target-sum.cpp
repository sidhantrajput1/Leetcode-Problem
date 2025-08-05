class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> dp;
    int helper(int n, int k, int t) {
        if (n == 0 and t == 0) return 1;
        if ( n == 0) return 0;

        if (dp[n][t] != -1) return dp[n][t];

        int sum = 0;
        for (int v = 1; v <= k; v++) {
            if (t - v < 0) continue;
            sum = (sum + helper(n-1, k, t - v)) % MOD; 
        }

        return dp[n][t] = sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        return helper(n, k, target);
    }
};