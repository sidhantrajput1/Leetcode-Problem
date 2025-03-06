class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(m*n);
        int idx = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[idx++] = grid[i][j];
            }
        }

        int sum = 0;
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            cout<<ans[i]<<" ";
        }

        vector<int> v;

        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] == ans[i-1]) {
                v.push_back(ans[i]);
            }
        }

        int missing = 1;
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == missing) missing++;
            else if (ans[i] > i) break;
        }

        v.push_back(missing);

        return v;
    }
};