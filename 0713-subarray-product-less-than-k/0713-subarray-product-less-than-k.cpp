class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int n = nums.size();
        int i = 0, j = 0;

        int count = 0, product = 1;

        while(j < n) {
            product *= nums[j];

            while (product >= k) {
                count = count + (j - i);
                product /= nums[i];
                i++; 
            }
            j++;
        }

        while (i < n) {
            count = count + (j - i);
            product /= nums[i];
            i++; 
        }    

        return count;    
    }
};