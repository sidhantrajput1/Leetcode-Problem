class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int st = 0;
        int end = r * c - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int midEle = matrix[mid/c][mid%c];
            
            if (midEle == target) return true;
            else if (target < midEle) end = mid - 1;
            else st = mid + 1;
        }
        
        return false;
    }
};