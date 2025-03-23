class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {

        int m = a.size();
        int n = a[0].size();

        // Spiral print
        int minr = 0, minc = 0;
        int maxr = m - 1, maxc = n - 1;
        int totalEle = 0;

        vector<int> ans;

        cout << "Spiral order: ";
        while (totalEle < m * n) {
            // right
            for (int j = minc; j <= maxc && totalEle < m * n; j++) {
                ans.push_back(a[minr][j]);
                totalEle++;
            }
            minr++;

            // down
            for (int i = minr; i <= maxr && totalEle < m * n; i++) {
                ans.push_back(a[i][maxc]);
                totalEle++;
            }
            maxc--;

            // left
            for (int j = maxc; j >= minc && totalEle < m * n; j--) {
                ans.push_back(a[maxr][j]);
                totalEle++;
            }
            maxr--;

            // up
            for (int i = maxr; i >= minr && totalEle < m * n; i--) {
                ans.push_back( a[i][minc]);
                totalEle++;
            }
            minc++;
        }

        return ans;
    }
};