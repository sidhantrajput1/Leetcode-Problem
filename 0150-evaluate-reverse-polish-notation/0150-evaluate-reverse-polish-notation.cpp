class Solution {
public:
    int operate(int a, int b, string token) {
        if (token == "+") {
            return a + b;
        } else if (token == "-") {
            return a - b;
        } else if (token == "*") {
            return a * b;
        }

        return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = st.top();
                st.pop(); // right operand
                int b = st.top();
                st.pop(); // left operand
                int result = operate(b, a, token);
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};