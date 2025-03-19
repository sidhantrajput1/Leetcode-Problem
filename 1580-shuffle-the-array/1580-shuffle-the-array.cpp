class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n;
        int si = nums.size();

        vector<int > ans;
        int idx = 0;
        while (i < n && j < si) {
            int s = nums[i];
            int t = nums[j];
            ans.push_back(s);
            ans.push_back(t);
            i++;
            j++;
        }

        return ans;
    }
};