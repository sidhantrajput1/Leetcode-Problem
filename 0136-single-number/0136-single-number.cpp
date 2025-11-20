class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int x : nums) {
            result ^= x;   // XOR cancels duplicate numbers
        }
        return result;
    }
};