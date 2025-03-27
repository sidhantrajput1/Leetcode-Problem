class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
                break;
            } else if (target < nums[mid] ) {
                end = mid - 1;
            } 
            else {
                st = mid + 1;
            }
        }

        return -1;
    }
};