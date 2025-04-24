class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int k) {
        int i = 0, j = k ;
        int n = nums.size();
        vector<int> ans;
        while (i < k  && j < n ) {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++; 
            j++;
        }
        return ans;
    }
};