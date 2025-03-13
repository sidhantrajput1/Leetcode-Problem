class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());


        vector<int> ans(n);

        ans[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            ans[i] = nums[i] + ans[i+1];
        }
        
        int idx = -1;

        for(int i = 0; i < ans.size(); i++) {
           if(ans[i] > 0) {
            idx = i;
            break;

           }
        }
        if(idx == -1) return 0;
        int x = 1;
        int maxx = 0;
        for(int i =idx; i<n; i++) {
            maxx = maxx + nums[i]*x;
            x++;
        }

        return maxx;
    }
};