class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        // 1. find the sum of nums array
        for (int num : nums) sum += num;

        // find the n  number of sum 
        int nSum = (n * (n + 1))/2;

        // return the missing number
        return nSum - sum;
    }
};