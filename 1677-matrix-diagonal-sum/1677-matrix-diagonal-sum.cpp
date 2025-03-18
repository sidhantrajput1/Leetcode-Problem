class Solution {
public:
    int diagonalSum(vector<vector<int>>& nums) {
        // 1 5 9 3 5 7
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            ans += nums[i][i];
            ans += nums[i][n-i-1];
        }

        if(n % 2 != 0) {
            ans = ans - nums[n/2][n/2];
        }

        return ans;
    }
};