class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0; // store the number of connected component

        for(int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) 
            {
                // it is water body
                if (grid[r][c] == '0') continue;

                // new unvisited land found i.e new connected component found
                cc++;

                // mark visited
                grid[r][c] = '0';

                // apply bfs
                queue<pair<int, int> > qu;
                qu.push({r, c});

                while (!qu.empty()) {
                    auto curr = qu.front(); // get one node from queue
                    qu.pop();

                    // go to all unvisited neighbour curr node
                    int currRow = curr.first;
                    int currCol = curr.second;

                    // check up
                    if (currRow - 1 >= 0 && grid[currRow - 1][currCol] == '1') {
                        qu.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = '0';
                    }

                    // check down
                    if (currRow + 1 < rows && grid[currRow + 1][currCol] == '1') {
                        qu.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = '0';
                    }

                    // check left
                    if (currCol - 1 >= 0 && grid[currRow][currCol - 1] == '1') {
                        qu.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = '0';
                    }

                    // check up
                    if (currCol + 1 < cols && grid[currRow][currCol + 1] == '1') {
                        qu.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = '0';
                    }
                }
            }
        }

        return cc;
    }
};