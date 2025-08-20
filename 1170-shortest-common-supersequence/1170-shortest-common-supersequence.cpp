class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Fill DP table
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Backtrack to build result
        string res = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                res.push_back(s1[i - 1]);
                i--; j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    res.push_back(s1[i - 1]);
                    i--;
                } else {
                    res.push_back(s2[j - 1]);
                    j--;
                }
            }
        }

        // Add remaining characters
        while (i > 0) {
            res.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            res.push_back(s2[j - 1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
