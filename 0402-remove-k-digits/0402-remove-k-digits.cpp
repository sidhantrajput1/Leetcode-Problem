class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";

        for (int i = 0; i < num.size(); i++) {
            while (res.length() > 0 && res.back() > num[i] && k > 0) {
                res.pop_back();
                k--;
            }
            if (res.length() > 0 || num[i] != '0') {
                res.push_back(num[i]);
            }
        }

        // remove remaining digits if k > 0
        while (k > 0 && res.length() > 0) {
            res.pop_back();
            k--;
        }

        // if empty, return "0"
        if (res.empty()) return "0";

        return res;
    }
};
