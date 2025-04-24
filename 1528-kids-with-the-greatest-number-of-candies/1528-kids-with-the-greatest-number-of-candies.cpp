class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n = candies.size();
        int maxKids = *max_element(candies.begin(), candies.end());

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