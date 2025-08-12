class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        // fill ans[0][0] = grid[0][0]
        ans[0][0] = grid[0][0];

        // fill the first col
        for(int col = 1; col < n; col++) {
            ans[0][col] = grid[0][col] + ans[0][col-1];
        }

        // fill the first row
        for (int row = 1; row < m; row++) {
            ans[row][0] = grid[row][0] + ans[row-1][0];
        }

        // fill the remaning
        for(int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] = grid[i][j] + min(ans[i-1][j], ans[i][j-1]);
            }
        }

        return ans[m-1][n-1];
    }
};