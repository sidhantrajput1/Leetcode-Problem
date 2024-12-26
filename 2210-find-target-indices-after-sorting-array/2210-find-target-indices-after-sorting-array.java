class Solution {
    public List<Integer> targetIndices(int[] nums, int target) {
        int count  = 0;
        int num = 0;

        for(int i = 0 ; i < nums.length; i++) {
            if(nums[i] == target) {
                count++;
            } else if (nums[i] < target) {
                num++;
            }
        }

        List<Integer> ans = new ArrayList<>();
        while(count>0) {
            ans.add(num);
            num++;
            count--;
        }
        return ans;
    }
}