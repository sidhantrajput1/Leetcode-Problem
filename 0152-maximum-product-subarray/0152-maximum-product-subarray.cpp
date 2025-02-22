class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;

        int n = nums.size();
        int currPrd = 1, currPrdB = 1,  maxPrd = nums[0];

        for(int i = 0; i < n; i++) {
            currPrd *= nums[i];
            currPrdB *= nums[n-1-i];
            maxPrd = max(maxPrd, max(currPrd, currPrdB));
            if(currPrd == 0) currPrd = 1;
            if(currPrdB == 0) currPrdB = 1;
        }
        return maxPrd;
    }
};