class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        unordered_set<int> s;

        for (auto x : map) {
            int freq = x.second;
            if(s.find(freq) != s.end()) return false; // freq mil jaye to false return kar do
            else s.insert(freq);
        }

        return true;
    }
};