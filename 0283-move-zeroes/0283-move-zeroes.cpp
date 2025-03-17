class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
    
        int left = 0;
        for(int right = 0; right < v.size(); right++){
            if(v[right] != 0) {
                swap(v[right], v[left]);
                left++;
            }
        }
    }
};