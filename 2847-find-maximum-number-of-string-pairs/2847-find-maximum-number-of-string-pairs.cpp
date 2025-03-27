class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& nums) {
        int count = 0;
        int n = nums.size();
        unordered_set<string> s;

        for (int i = 0; i < n; i++) {
            string rev = nums[i];
            reverse(rev.begin(), rev.end());

            if (s.find(rev) != s.end()) count++;
            else s.insert(nums[i]);
        }
        return count;
    }
};