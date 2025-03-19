class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minVal = 0 , prefixSum = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            minVal = min(minVal, prefixSum);
        }

        return 1 - minVal;
    }
};