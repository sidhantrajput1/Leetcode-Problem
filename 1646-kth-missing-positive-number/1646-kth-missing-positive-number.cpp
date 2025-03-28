class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int howManyMissingNumber = nums[mid] - (mid + 1);

            if (howManyMissingNumber < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }
};