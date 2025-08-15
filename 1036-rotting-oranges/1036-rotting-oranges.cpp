class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        int fo = 0; // count fresh oranges

        int n = grid.size();
        int m = grid[0].size();

        // Count fresh oranges & push rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) fo++; // fresh orange
                else if (grid[i][j] == 2) qu.push({i, j}); // multi source BFS
            }
        }

        if (fo == 0) return 0; // no fresh orange

        qu.push({-1, -1}); // level marker
        int mins = 0;

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!qu.empty()) {
            auto cell = qu.front();
            qu.pop();

            int i = cell.first;
            int j = cell.second;

            if (i == -1 && j == -1) {
                mins++;
                if (!qu.empty()) qu.push({-1, -1});
            } else {
                for (auto &d : dir) {
                    int nr = i + d[0];
                    int nc = j + d[1];

                    if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                    if (grid[nr][nc] != 1) continue; // must be fresh

                    fo--; // one fresh orange rotted
                    grid[nr][nc] = 2;
                    qu.push({nr, nc});
                }
            }
        }

        return (fo == 0) ? mins - 1 : -1;
    }
};
