class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0; 
        int j = cols - 1;
        
        while( i <= rows-1 && j >= 0) {
            if (matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--;
            else i++; // matrix[i][j] < target
        }

        return false;
    }
};