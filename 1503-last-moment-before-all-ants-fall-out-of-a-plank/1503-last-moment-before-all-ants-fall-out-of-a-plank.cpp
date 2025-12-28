class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (auto &X : left) {
            res = max(res, X);
        }

        for(auto &X : right) {
            res = max(res, n - X);
        }
        return res;
    }
};