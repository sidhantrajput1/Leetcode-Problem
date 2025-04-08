
class Solution {
public:
    vector<int> nums; // Make nums accessible in class scope

    bool check(int start) {
        unordered_set<int> st;
        for (int j = start; j < nums.size(); j++) {
            if (st.count(nums[j])) {
                return false;
            }
            st.insert(nums[j]);
        }
        return true;
    }

    int minimumOperations(vector<int>& inputNums) {
        nums = inputNums;
        int n = nums.size();
        int operation = 0;

        for (int i = 0; i < n; i += 3) {
            if (check(i)) {
                return operation;
            }
            operation++;
        }
        return operation;
    }
};
