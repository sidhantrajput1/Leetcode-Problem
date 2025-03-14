class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);

        // step 1 : sort the array
        sort(nums.begin(), nums.end());

        // find prefix sum
        for(int i = 1; i < n; i++) {
            nums[i] = nums[i] + nums[i-1];
        }

        // find answer queries
        for(int i = 0; i < m; i++) {
            int maxLen = 0;
            int st = 0, end = n-1;
            while(st <= end) {
                int mid = st + (end - st) / 2;
                if(nums[mid] > queries[i]) end = mid - 1;
                else {
                    maxLen = mid + 1;
                    st = mid + 1;
                }
            }
            ans[i] = maxLen;
        }

        // return ans;
        return ans;
    }
};