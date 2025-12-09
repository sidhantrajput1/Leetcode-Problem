class Solution {
public:
    int firstIndex(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == nums[mid]) {
                ans = mid;
                end = mid - 1;
            } else if (target < nums[mid])
                end = mid - 1;
            else
                st = mid + 1;
        }

        return ans;
    }
    int lastIndex(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == nums[mid]) {
                ans = mid;
                st = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstIndex(nums, target);
        int last = lastIndex(nums, target);

        return {first, last};
    }
};