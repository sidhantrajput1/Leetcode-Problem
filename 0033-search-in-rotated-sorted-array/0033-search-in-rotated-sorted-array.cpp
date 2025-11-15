class Solution {
public:
    int findPivot(vector<int>& nums, int n) {
        int st = 0, end = n - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[end])
                st = mid + 1;
            else
                end = mid;
        }
        return end;
    }

    int binarySearch(int st, int end, vector<int>& nums, int target) {
        int idx = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                idx = mid;
                break;
            } else if (nums[mid] < target)
                st = mid + 1;
            else
                end = mid - 1;
        }
        return idx;
    }
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int pivot_idx = findPivot(nums, n);

        // left side of pivot idx
        int idx = binarySearch(0, pivot_idx, nums, target);

        if (idx != -1)
            return idx;

        // right side of pivot index
        idx = binarySearch(pivot_idx, n - 1, nums, target);

        return idx;
    }
};