class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n = candies.size();
        int maxKids = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (candies[i] > maxKids) {
                maxKids = candies[i];
            }
        }
        for(int i= 0; i < n; i++) {
            int mxCandies = candies[i] + extraCandies;
            if (mxCandies >= maxKids) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};