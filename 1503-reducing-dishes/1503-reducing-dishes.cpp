class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> suff(n);
        suff[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            suff[i] = nums[i] + suff[i+1];
        }

        int totalSum = 0;

        for(int i = 0; i < suff.size(); i++) {
            if(suff[i] < 0) continue;
            else totalSum += suff[i];
        }  
        return totalSum; 
    }
};