class Solution {
public:
   
    int evalRPN(vector<string>& tokens) {
         stack<int> st;

        unordered_map<string, function<int(int,int)>> mp = {
            {"+", [](int a, int b){ return a + b; }},
            {"-", [](int a, int b){ return a - b; }},
            {"*", [](int a, int b){ return a * b; }},
            {"/", [](int a, int b){ return a / b; }}
        };

        for (string& token : tokens) {
            if (mp.find(token) != mp.end()) {
                int a = st.top(); st.pop(); // right operand
                int b = st.top(); st.pop(); // left operand
                st.push(mp[token](b, a));   // important: left op right
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};