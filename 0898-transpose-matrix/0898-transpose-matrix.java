class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length; // row
        int n = matrix[0].length; // col

        int[][] ans = new int[n][m]; //dimension are swaped

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j]; 
            }
        }
        return ans;
    }
}