class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN; // Use LONG_MIN for comparison safety
        
        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue; // Skip duplicate values
            }
            
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        // If third maximum doesn't exist, return the first maximum
        return third == LONG_MIN ? first : third;
    }
};
