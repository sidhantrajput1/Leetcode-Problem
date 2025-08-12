class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < triangle[row].size(); col++) {
                int down = triangle[row + 1][col];
                int diag = triangle[row + 1][col + 1];
                triangle[row][col] += min(down, diag);
            }
        }
        return triangle[0][0];
    }
};