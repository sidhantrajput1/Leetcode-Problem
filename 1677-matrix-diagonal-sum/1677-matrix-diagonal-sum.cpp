class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r = mat.size();
    
        int sum = 0;
        
        // matrix diagonal sum
        for(int i = 0; i < r; i++) {
            sum = sum + mat[i][i];
            sum = sum + mat[i][r-i-1];
        }
        
        if (r % 2 != 0) {
            sum = sum - mat[r/2][r/2];
        }

        return sum;
    }
};