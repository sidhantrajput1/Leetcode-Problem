class Solution {
public:
    int helper(int sr, int sc, int er, int ec, vector<vector<int>>& nums, vector<vector<int>>& dp) {
        if (sr > er || sc > ec) return INT_MAX;
        if (sr == er && sc == ec) return nums[sr][sc];

        if (dp[sr][sc] != -1) return dp[sr][sc];

        int rightWays = helper(sr, sc+1, er, ec, nums, dp);
        int bottomWays = bottomWays = helper(sr+1, sc , er, ec, nums, dp);
        
        dp[sr][sc] = nums[sr][sc] + min(rightWays, bottomWays);

        return dp[sr][sc];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 

        vector<vector<int>> dp(m, vector<int>(n, -1));   
        
        return helper(0, 0, m-1, n-1, grid, dp);
    }
};