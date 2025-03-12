class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto lower = lower_bound(nums.begin(), nums.end(), 0);
        int countNeg = lower - nums.begin();
        auto upper = upper_bound(nums.begin(), nums.end(), 0);
        int countPos = nums.end() - upper;
        return max(countPos, countNeg);
    }
};