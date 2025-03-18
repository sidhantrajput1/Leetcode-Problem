class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int minLen = INT_MAX, len = 0, sum = 0;

        while (j < n) {
            sum += nums[j];

            while (sum >= target) {
                len = j - i + 1;
                minLen = min(minLen, len);
                sum = sum - nums[i];
                i++;
            }
            j++;
            
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};