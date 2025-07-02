class Solution {
public:
    // sr = starting row , sc = starting col, er = ending row and ec = ending col
    int helper(int sr, int sc, int er, int ec, vector<vector<int>>& dp) {
        if (sr == er && sc == ec) return 1;
        // if starting row > ending row || starting col > ending col then always return 0
        if (sr > er || sc > ec) return 0;

        if (dp[sr][sc] != -1) return dp[sr][sc];
        
        return dp[sr][sc] = helper(sr + 1, sc, er, ec, dp) + helper(sr, sc + 1, er, ec, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // starting colum 0 and starting row is also 0. 
        // robot tries to move to the bottom-right corner grid[m - 1][n - 1] 
        return helper(0, 0, m - 1, n - 1, dp);
    }
};