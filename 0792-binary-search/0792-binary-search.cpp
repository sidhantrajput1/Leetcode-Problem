class Solution {
public:
    int search(vector<int>& v, int target) {
        int st = 0;
        int end = v.size() - 1;
        
        
        while (st <= end) {
            int mid = st + (end-st)/2;
            
            if (v[mid] == target) {
                return mid;
                break;
            } else if (v[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};