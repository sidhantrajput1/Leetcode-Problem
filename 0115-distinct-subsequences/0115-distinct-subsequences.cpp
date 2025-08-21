class Solution {
public:
    int dp[1001][1001];

    int helper(int i, int j, string s, string t) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = helper(i - 1, j - 1, s, t) + helper(i - 1, j, s, t);
        }

        return dp[i][j] = helper(i - 1, j, s, t);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        memset(dp, -1, sizeof(dp));

        return helper(m - 1, n - 1, s, t);
    }
};