class Solution {
public:
    int countNegatives(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        int count = 0;
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mat[i][j] < 0) count++;
            }
        }

        return count;
    }
};