class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res(nums.size());
        int low = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) {
                res[low] = nums[i];
                low++;
            }
        }

        // second pass
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == pivot) {
                res[low] = nums[i];
                low++;
            }
        }

        // third pass
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > pivot ){
                res[low] = nums[i];
                low++;
            }
        }

        return res;
    }
};