class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(int ele:nums){
            mp[ele]++;
       }
       for(const auto& ele : mp){
            if(ele.second >=2) return true;
       } 
       return false;
    }
};