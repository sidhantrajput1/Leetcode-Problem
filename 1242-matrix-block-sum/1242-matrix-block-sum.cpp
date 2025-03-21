class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> ans(r, vector<int>(c));
    
        for(int row = 0; row < r; row++) {
                for (int col = 0; col < c; col++) {
                    int idxSum = 0;
                        for(int i = row - k; i <= row + k; i++) {
                            for(int j = col - k; j <= col + k; j++) {
                                // i >= 0 && i < r && j >= 0 && j < c
                                if (i >= 0 && i < r && j >= 0 && j < c ) idxSum += mat[i][j];
                            }
                        }
                    ans[row][col] = idxSum;
                }
            }

        return ans; 
    }  
};