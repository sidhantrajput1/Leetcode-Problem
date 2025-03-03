class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        int low = 0;

        // first pass : if element less than pivot element 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) {
                res[low] = nums[i];
                low++;
            }
        }

        // second pass : if element equal to pivot element
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == pivot) {
                res[low] = nums[i];
                low++;
            }
        }

        // third pass : if element greater to pivot element 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > pivot ){
                res[low] = nums[i];
                low++;
            }
        }

        return res;
    }
};