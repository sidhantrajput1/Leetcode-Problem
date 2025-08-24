class Solution {
public:
     void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int& e) {
        visited[node] = true;
        v++;                          // count vertices
        e += adj[node].size();        // count edges (will be double counted)

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, v, e);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        int result = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if(visited[i]) continue;
            else {
                int v = 0, e = 0;

                dfs(i, adj, visited, v, e);

                if (v * (v - 1) == e) {
                    result++;
                }
            }
        }

        return result;
    }
};