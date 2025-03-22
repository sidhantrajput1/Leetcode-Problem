class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& nums, int m, int n) {

        vector<vector<int>> mat(m , vector<int>(n));

        if (nums.size() != m*n) {
            return {};
        }

        for (int i = 0; i < m * n; i++) {
            mat[i / n][i % n] = nums[i];
        }

        return mat;
    }
};