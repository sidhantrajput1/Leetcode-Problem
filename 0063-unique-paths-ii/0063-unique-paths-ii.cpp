class Solution {
public:
    int helper(int sr, int sc, int er, int ec,vector<vector<int>>& nums, vector<vector<int>>& dp) {
        if (sr > er || sc > ec) return 0;
        if (sr == er && sc == ec) return 1;
        
        // obstacle check
        if (nums[sr][sc] == 1 || nums[er][ec] == 1) return 0;

        if (dp[sr][sc] != -1) return dp[sr][sc];
        
        int downWays = helper(sr+1, sc, er, ec, nums, dp);
        int rightWays = helper(sr, sc+1, er, ec, nums, dp);
        
        return dp[sr][sc] = downWays + rightWays;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();    
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // if starting and ending cell is blocked then return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        return helper(0, 0, m-1, n-1, obstacleGrid, dp);
    }
};