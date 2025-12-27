class Solution {
public:
    vector<vector<int>> result;
    void twoSum(vector<int>& nums, int target, int st, int end) {
        int n = nums.size();
        
        
        while (st < end) {
            int sum = nums[st] + nums[end];
            
            if (sum > target) {
                end--;
            } else if (sum < target) {
                st++; 
            } else {
                while (st < end && nums[st] == nums[st+1]) st++;
                while (st < end && nums[end] == nums[end-1]) end--;

                result.push_back({-target, nums[st], nums[end]});
                st++;
                end--;
            }
        }
        
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return {};
        
        // sort the arr first
        sort(begin(nums), end(nums));

        result.clear();

        // fixing one element n1
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int n1 = nums[i];
            int target = -n1;

            // call the two sum : it will find n2 and n3 : {n1, n2, n3}
            twoSum(nums, target, i+1, n - 1);
        }

        return result;
    }   
};