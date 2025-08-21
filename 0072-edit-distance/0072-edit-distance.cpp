class Solution {
public:
    int m , n;
    int dp[501][501];
    int helper(string s1, string s2, int i, int j) {
        if (i == m) return n - j;
        if (j == n) return m - i;

        if (dp[i][j] != -1) return dp[i][j];
        
        // if s1[i] == s2[j]
        if (s1[i] == s2[j]) {
            return dp[i][j] = helper(s1, s2, i + 1, j + 1);
        }

        // insert
        int insert = helper(s1, s2, i, j + 1);
        // delete
        int delet = helper(s1, s2, i + 1, j);
        // replace
        int replace = helper(s1, s2, i + 1, j + 1);

        // int replace = 0;
        // int delet = 0;
        // int insert = 0;

        // if (s1[i] != s2[j]) {
        //     insert = helper(s1, s2, i, j + 1);
        //     delet = helper(s1, s2, i + 1, j);
        //     replace = helper(s1, s2, i + 1, j + 1);
        // }

        return dp[i][j] = 1 + min({insert, delet , replace});
    }
    int minDistance(string s1, string s2) {
        m = s1.size(), n = s2.size();
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, 0, 0);
    }
};