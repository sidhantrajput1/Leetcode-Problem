class Solution {
public:
    int m, n;
    int dp[2001][2001]; // -1 = not computed, 0 = false, 1 = true

    bool helper(int i, int j, string &s, string &p) {
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;

        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, s, p);
        } 

        if (p[j] == '*') {
            return dp[i][j] = (helper(i - 1, j, s, p) || helper(i, j - 1, s, p));
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        m = s.size(), n = p.size();
        memset(dp, -1, sizeof(dp));
        return helper(m - 1, n - 1, s, p);
    }
};
