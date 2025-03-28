class Solution {
public:
    int lastNegtiveIdx(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        int firstNeg = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] < 0) {
                firstNeg = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return firstNeg;
    }

    int firstPostiveIdx(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size() - 1;
        
        int firstPos = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > 0) {
                firstPos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return firstPos;
    }

    int maximumCount(vector<int>& nums) {

        int firstPos = nums.size() - firstPostiveIdx(nums);
        int lastNeg = lastNegtiveIdx(nums)+1;

        return max(lastNeg, firstPos);
    }
};