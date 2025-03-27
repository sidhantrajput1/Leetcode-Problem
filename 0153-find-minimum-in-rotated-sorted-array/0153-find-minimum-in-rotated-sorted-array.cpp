class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0,hi=nums.size()-1;
        while(lo<hi){
            int mid = lo +(hi-lo)/2;
            if(nums[mid]>nums[hi]){
                lo = mid+1;
            }else{
                hi=mid;  // may be possible that it may be the smallest element so we do hi=mid , insted of hi=mid-1
            }
        }
        return nums[lo];  // also return nums[hi]
    }
};