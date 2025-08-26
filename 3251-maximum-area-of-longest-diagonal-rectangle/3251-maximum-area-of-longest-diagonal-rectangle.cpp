class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int mxDig = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int digSq = l * l + w * w;
            int area = l * w;

            // choose the rectangle with longer diagonal
            // if diagonals are equal, choose larger area
            if (digSq > mxDig || (digSq == mxDig && area > ans)) {
                mxDig = digSq;
                ans = area;
            }
        }

        return ans;
    }
};