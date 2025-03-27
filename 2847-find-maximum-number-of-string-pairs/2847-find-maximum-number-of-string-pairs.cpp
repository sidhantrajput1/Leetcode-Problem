class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& nums) {
        int count = 0;
        int n = nums.size();
        unordered_set<string> s;

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            string rev = nums[i];
            reverse(rev.begin(), rev.end());

            if (rev == nums[i]) continue;
            if ( s.find(rev) != s.end() ) {
                count++;
                s.erase(nums[i]);
            }
        }
        return count;
    }
};