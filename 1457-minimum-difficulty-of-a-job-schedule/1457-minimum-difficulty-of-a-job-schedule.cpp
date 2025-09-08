class Solution {
public:
    int dp[302][11];
    int solve(vector<int>& jd, int n, int idx, int d) {
        /*
            BASE CASE 1
            if there is only day 1 left, then you have to do all remaining jobs in that one day
            and find the max diffculty of that day and return it 
        */

        if (d == 1) {
            int maxD = jd[idx];

            for (int i = idx; i < n; i++) {
                maxD = max(maxD, jd[i]);
            }
            return maxD;
        }

        if (dp[idx][d] != -1) return dp[idx][d];

        int maxD = jd[idx];
        int finalResult = INT_MAX;

        /*
            Try One by one with all posibillty 

            Take index = {idx} wala job in first day 
            Take index = {idx, idx + 1} wala job in first day 
            Take index = {idx, idx + 1, idx + 2} wala job in first day 
            ..
            .. so on..
        */

        // the find the optimal one among all the result

        for (int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jd[i]);
            int result = maxD + solve(jd, n, i + 1, d - 1);

            finalResult = min(finalResult, result);
        }

        return dp[idx][d] = finalResult;
    }


    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();

        if (n < d) return -1;

        memset(dp, -1, sizeof(dp));

        return solve(jd, n, 0, d);
    }
};