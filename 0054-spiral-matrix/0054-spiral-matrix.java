class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();

        int r = matrix.length;
        int c = matrix[0].length;

        int topRow = 0;
        int bottomRow = r - 1;
        int  leftCol = 0;
        int rightCol = c -1;

        int totalElement = 0;

        while(totalElement < r * c) {
            // topRow -> leftCol to rightCol
            for(int j = leftCol; j <= rightCol && totalElement < r * c; j++) {
                ans.add(matrix[topRow][j]);
                totalElement++;
            }
            topRow++;

            // rightCol -> topRow to BottomRow 
            for(int i = topRow; i <= bottomRow && totalElement < r * c; i++) {
                ans.add(matrix[i][rightCol]);
                totalElement++;
            }
            rightCol--;

            // bottomRow -> rightCol to leftCol
            for(int j = rightCol; j >= leftCol && totalElement < r * c; j--) {
                ans.add(matrix[bottomRow][j]);
                totalElement++;
            }
            bottomRow--;

            // leftCol -> bottomRow to topRow
            for(int i = bottomRow; i >= topRow && totalElement < r * c; i--) {
                ans.add(matrix[i][leftCol]);
                totalElement++;
            }
            leftCol++;
        }

        return ans;
    }
}