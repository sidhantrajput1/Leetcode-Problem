class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minWinLength = INT_MAX;
        int currSum = 0;

        int low = 0, high = 0;

        while (high < n) {
            currSum += nums[high];
            high++;

            // try to reduce window size
            while(currSum >= target) {
                int currWinSize = high - low;

                // update minimum length of window
                minWinLength = min(minWinLength, currWinSize);
                currSum = currSum - nums[low];
                low++;
            }
        }

        return (minWinLength == INT_MAX) ? 0 : minWinLength;
    }
};