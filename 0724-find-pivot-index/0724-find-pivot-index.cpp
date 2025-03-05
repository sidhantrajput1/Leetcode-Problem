class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        
        int leftSum = 0;
        // Iterate through the array to find the pivot index
        for(int i = 0; i < n; i++) {
            // Right sum = totalSum - leftSum - current element (nums[i])
            int rightSum = totalSum - leftSum - nums[i];

            if(leftSum == rightSum) return i;

            leftSum += nums[i];
        }

        return -1;
    }
};