class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int s0 = 0;
        int s1 = 0;
        int s2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) s0 = s0 + 1;
            else if (nums[i] == 1) s1 = s1 + 1;
            else s2 = s2 + 1;
        }
        
        int idx = 0;
        for(int i = 0; i < s0; i++) nums[idx++] = 0;
        for(int i = 0; i < s1; i++) nums[idx++] = 1;
        for(int i = 0; i < s2; i++) nums[idx++] = 2;
    }
}