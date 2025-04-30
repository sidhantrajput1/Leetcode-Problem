class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while(left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++; right--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1 -> Find pivot index
        // Find the pivot (first decreasing element from the right).
        int idx = -1;
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                idx = i;
                break;
            }
        }
        
        // // If no pivot found, reverse the entire array
        if(idx == -1) {
            reverse(nums, 0, nums.size()-1);
            return;
        }

        // Step 2 -> reverse the idx+1 to n-1, after the finding pivot
        reverse(nums, idx+1, n-1);

        // Step 3 -> Finding the just grater element than idx
        int j = -1;
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }

        // Step -> Swap the idx to idx+1
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;
    }
};