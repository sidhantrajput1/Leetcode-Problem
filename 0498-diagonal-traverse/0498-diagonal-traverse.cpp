class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m * n);

        for (int d = 0; d < m + n - 1; d++) {
            vector<int> temp;

            int r = d < n ? 0 : d - n + 1;
            int c = d < n ? d : n - 1;

            for (; r < m && c >= 0; r++, c--) {
                temp.push_back(mat[r][c]);
            }

            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};