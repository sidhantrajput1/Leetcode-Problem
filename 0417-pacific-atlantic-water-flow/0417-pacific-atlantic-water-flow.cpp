class Solution {
public:

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;
    vector<vector<int>> h;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        h = heights;

        // Step of multisource bfs
        queue<pair<int, int>> pecific;
        queue<pair<int, int>> atlantic;

        for (int i = 0; i < rows; i++) {
            pecific.push({i, 0});
            atlantic.push({i, cols-1});
        }

        for(int j = 0; j < cols; j++) {
            pecific.push({0, j});
        }

        for(int j = 0; j < cols-1; j++) {
            atlantic.push({rows-1, j});
        }

        vector<vector<bool>> pecificA = bfs(pecific);
        vector<vector<bool>> atlanticA = bfs(atlantic);

        vector<vector<int>> result;;

        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pecificA[i][j] && atlanticA[i][j]) result.push_back({i, j});
            }
        }

        return result;
    }

    vector<vector<bool> > bfs(queue<pair<int, int>>& qu) {

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        while(!qu.empty()) {

            auto cell = qu.front();
            qu.pop();

            int i = cell.first;
            int j = cell.second;

            visited[i][j] = true;

            for (int d = 0; d < 4; d++) {

                int newRow = i + dir[d][0];
                int newCol = j + dir[d][1];

                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue; //
                if (visited[newRow][newCol]) continue;

                if (h[newRow][newCol] < h[i][j]) continue; // h[newRow][newCol] -> neighbour height, h[i][j] current cell height
                qu.push({newRow, newCol});

             }
        }

        return visited;
    }
};