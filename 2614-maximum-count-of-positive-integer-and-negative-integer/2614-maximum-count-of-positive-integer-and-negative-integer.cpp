class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int maxPos = 0;
        int maxNeg = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) continue;
            if(nums[i] < 0) {
                maxNeg++;
            } else {
                maxPos++;
            }
        }

        return max(maxPos, maxNeg);
    }
};