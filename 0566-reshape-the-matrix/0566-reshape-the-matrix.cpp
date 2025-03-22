class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(); // number of rows
        int n = nums[0].size(); // number of cols
        
        vector<vector<int>> mat(r, vector<int>(c));

        if (m * n != r * c) {
            return nums;
        }
        
        for(int i = 0; i < m * n; i++) {
            mat[i / c][i % c] = nums[i / n][ i % n];
        }

        return mat;
    }
};