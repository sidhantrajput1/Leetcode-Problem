class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                // value already seen before
                if (abs(i - mp[nums[i]]) <= k) 
                    return true;
            } 
            // update the last index of the value
            mp[nums[i]] = i;
        }
        
        return false;
    }
};