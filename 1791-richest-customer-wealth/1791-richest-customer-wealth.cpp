class Solution {
public:
    int maximumWealth(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        int maxSum = 0;
        
        for(int i = 0; i < r; i++) {
            int currSum = 0;
            for(int j = 0; j < c; j++) {
                currSum += mat[i][j];
            }
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};