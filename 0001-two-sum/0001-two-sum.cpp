class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp; // store val, index

        for (int i = 0; i < n; i++) {
            int remaining = target - nums[i];
            // check remaing value present in map or not.
            if (mp.find(remaining) != mp.end()) {
                return {mp[remaining], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};