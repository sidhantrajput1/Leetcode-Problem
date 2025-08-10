class Solution {
public:
    vector<int> dp;
    int helper(int n) {
        if ( n == 1 || n == 2) return n;

        if (dp[n] != -1) return dp[n];

        int oneStep = helper(n - 1);
        int twoStep = helper(n - 2);

        return dp[n] = oneStep + twoStep;
    }
    int climbStairs(int n) {
        dp.clear();
        dp.resize(50, -1);

        return helper(n);
    }
};