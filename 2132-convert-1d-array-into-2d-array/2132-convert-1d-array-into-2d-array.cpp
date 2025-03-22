class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {

        vector<vector<int>> mat(m , vector<int>(n));

        if (nums.size() != m*n) {
            return {};
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = nums[i*n+j];
            }
        }

        return mat;
    }
};