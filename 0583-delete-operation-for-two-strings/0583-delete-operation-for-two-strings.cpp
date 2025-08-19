class Solution {
public:
    int m, n;
    int dp[501][501];
    int helper(string &s1, string &s2, int i, int j) {
        if (i >= m) return n - j; 
        if (j >= n) return m - i;

        if ( dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = helper(s1, s2, i + 1, j + 1);
        } 
        else {
            int dels1 = 1 + helper(s1, s2, i + 1, j);
            int dels2 = 1 + helper(s1, s2, i, j + 1);
            return dp[i][j] = min(dels1, dels2);
        }
        
    } 
    int minDistance(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        memset(dp, -1, sizeof(dp));

        return helper(s1, s2, 0, 0);
    }
};