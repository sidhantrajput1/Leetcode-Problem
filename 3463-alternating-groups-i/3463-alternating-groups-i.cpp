class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for( int i = 0; i < nums.size(); i++) {
            int next1 = (i + 1) % n;
            cout<<next1<<" ";
            int next2 = (i + 2) % n;
            cout<<next1<<" ";
            if(nums[i] != nums[next1] && nums[next1] != nums[next2]) {
                count++;
            }
        }
        return count;
    }
};