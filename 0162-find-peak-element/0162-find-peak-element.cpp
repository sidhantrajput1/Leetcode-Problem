class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        
        int idx = 0;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if ((mid == 0 || nums[mid] > nums[mid-1]) &&  (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
                break;
            } else if (nums[mid] < nums[mid + 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};