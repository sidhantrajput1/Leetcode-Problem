class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++) {

            int j = i + 1, k = n - 1;
            int com = target - nums[i];

            while(j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (abs(currSum - target) < abs(ans - target)) ans = currSum;

                if(nums[j] + nums[k] == com) return ans;
                else if (nums[j] + nums[k] > com) k--;
                else j++;
            }
            
        }
        return ans;
    }
};