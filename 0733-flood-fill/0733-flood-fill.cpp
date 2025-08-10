class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        dfs(image, sr, sc, initialColor, color);
        return image;
    }

    void dfs(vector<vector<int> >& image, int currRow, int currCol, int initialColor, int newColor) {
        int n = image.size(); // total rows
        int m = image[0].size(); // total Cols

        if (currRow < 0 || currCol < 0 || currRow >= n || currCol >= m) {
            return;
        }

        if (image[currRow][currCol] != initialColor) return;

        image[currRow][currCol] = newColor;
        dfs(image, currRow, currCol-1, initialColor, newColor); // left
        dfs(image, currRow, currCol+1, initialColor, newColor); // right
        dfs(image, currRow-1, currCol, initialColor, newColor); // up
        dfs(image, currRow+1, currCol, initialColor, newColor); // down
    }
};