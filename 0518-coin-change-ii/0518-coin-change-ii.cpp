class Solution {
public:

    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {

        if ( amount == 0 ) return 1;
        if (i == coins.size()) return 0;

        if (dp[i][amount] != -1) return dp[i][amount];
        
        if (coins[i] > amount) {
           return helper(i+1, amount, coins, dp);
        }

        int not_take = helper(i+1, amount, coins, dp);
        int take = helper(i, amount - coins[i], coins, dp);
        
        return dp[i][amount] = not_take + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        return helper(0, amount, coins, dp);
    }
};