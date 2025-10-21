class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            } 

            // if stack is not empty
            if (!st.empty()) {
                res[i] = st.top() - i;
            } else {
                res[i] = 0;
            }

            st.push(i);
        }

        return res;
    }
};