class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, minRange = 0, maxRange = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            minRange = max(minRange, i + nums[i]); 

            if (i == maxRange) {
                jumps++;
                maxRange = minRange;
            } 
        }

        return jumps;
    }
};