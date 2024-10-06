class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());

        if(nums1.size()%2==0){ // it means this sorted array has two element in the middle 
            int second_mid = nums1.size()/2;
            int first_mid = second_mid-1;

            int f_m = nums1[first_mid];
            int s_m = nums1[second_mid];

            double val = (f_m + s_m)/2.0;

            return val;
            
        }else{// means array length is odd
            return nums1[nums1.size()/2];
        }

        return 2.9;
    }
};