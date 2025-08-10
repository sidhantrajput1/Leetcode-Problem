class Solution {
public:
    vector<int> dp;

    int helper(vector<int>& nums, int i, int n) {
        if ( i > n) return 0;

        if (dp[i] != -1) return dp[i];

        int loot = nums[i] + helper(nums, i+2, n);
        int no_loot = helper(nums, i + 1, n);

        return dp[i] = max(loot , no_loot);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if ( n == 1) return nums[0]; 
        if ( n == 2) return max(nums[0], nums[1]);
        
        // Case 1 : start from 0 to n - 2, because first house is the neighbour of the last one.
        dp.assign(n, -1);
        int case1 = helper(nums, 0, n - 2);

        // Case 2 : start Rob from 1 to n - 1, because first house is the neighbour of the last house
        dp.assign(n, -1); // reset the array and assign the new value
        int case2 = helper(nums, 1, n - 1);

        // return maximum rob of houses
        return max(case1, case2);
    }
};