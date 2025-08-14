class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();

        int cc = 0; // number of connected components
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') { // found new unvisited land
                    cc++;
                    grid[r][c] = '0'; // mark visited

                    queue<pair<int, int>> qu;
                    qu.push({r, c});

                    while (!qu.empty()) {
                        auto [currRow, currCol] = qu.front();
                        qu.pop();

                        for (auto [dr, dc] : directions) {
                            int nr = currRow + dr;
                            int nc = currCol + dc;

                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                qu.push({nr, nc});
                                grid[nr][nc] = '0'; // mark visited
                            }
                        }
                    }
                }
            }
        }

        return cc;
    }
};