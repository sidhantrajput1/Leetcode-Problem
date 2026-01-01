class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        for (int i = n - 1; i >= 2; i--) {
            // nums[i] < nums[i+2] < nums[i+2];
            if (nums[i-1] + nums[i-2] > nums[i]) 
                return nums[i-1] + nums[i-2] + nums[i];
        }
        return 0;
    }
};