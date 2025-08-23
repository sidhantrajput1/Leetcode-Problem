class Solution {
public:
    int n;
    vector<bool> visited;
    void helper(int city, vector<vector<int>>& isConnected) {
        visited[city] = true;

        for (int neighbor = 0; neighbor  < n; neighbor++) {
            if (!visited[neighbor] && isConnected[city][neighbor] == 1) {
                helper(neighbor, isConnected); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visited.resize(n, false);    

        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                helper(i, isConnected);
            }
        }

        return provinces;
    }
};