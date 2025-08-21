class Solution {
public:
    int m , n;
    int dp[502][502];
    int helper(string s1, string s2, int i, int j) {
        // if any one string is empty then you need to return another string length, so if ( i == 0 ) return remaing string s2 length as well as for s1
        if ( i == 0 ) return j;  // insert all remaining of s2
        if ( j == 0 ) return i;  // insert all remaining of s1

        if (dp[i][j] != -1) return dp[i][j];
        
        if (s1[i-1] == s2[j-1]) {
            return dp[i][j] = helper(s1, s2, i - 1, j - 1);
        }

        return dp[i][j] = 1 + min({helper(s1, s2, i, j - 1), 
        helper(s1, s2, i - 1, j) , helper(s1, s2, i - 1, j - 1)});
    }
    int minDistance(string s1, string s2) {
        m = s1.size(), n = s2.size();
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, m, n);
    }
};