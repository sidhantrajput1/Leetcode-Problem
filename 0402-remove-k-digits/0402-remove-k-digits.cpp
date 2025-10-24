class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string res = "";

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            if (!st.empty() || num[i] != '0') {
                st.push(num[i]);
            }
        }

        // remove remaining digits if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // if empty, return "0"
        if (res.empty()) return "0";

        return res;
    }
};
