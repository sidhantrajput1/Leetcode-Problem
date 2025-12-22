class Solution {
public:
    string removeOuterParentheses(string s) {
        // step 1. if stack is empty push char in stack , do not add answer
        // step 2. if stack is not empty push char in stack but add in char in ans 
        // step 3. if opening bracket match to closing bracket then pop from stack and char add in answer
        // step 4. after the each step return the answer string

        string ans = "";
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    ans += c;   // not outer '('
                }
                st.push(c);
            } 
            else { // c == ')'
                st.pop();
                if (!st.empty()) {
                    ans += c;   // not outer ')'
                }
            }
        }

        return ans;
    }
};