class Solution {
public:
    void moveZero(vector<int>& nums) {
        // move zero to end
        int idx = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) nums[idx++] = nums[i];
        }
        while(idx < n) nums[idx++] = 0;
    }
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0; i < nums.size() -1; i++){
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            } 
        }
        moveZero(nums);
        return nums;
    }
};