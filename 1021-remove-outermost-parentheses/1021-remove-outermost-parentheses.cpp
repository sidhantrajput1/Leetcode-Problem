class Solution {
public:
    string removeOuterParentheses(string s) {
        /*
            Approach: Depth (Counter) Method

            - `count` represents the current depth of nested parentheses
            - We remove the "outermost" parentheses of every primitive substring

            Rules:
            1. When we see '(' → depth increases
            2. When we see ')' → depth decreases
            3. A character is part of the "outermost" parentheses if:
               - '(' when depth == 0
               - ')' when depth becomes 0 after decrement
            4. Only add characters to the answer when depth != 0
        */

        string ans = "";
        int count = 0;

        for (char c : s) {
            if (c == ')') count--;
            if (count != 0) {
                ans.push_back(c);
            }
            if (c == '(') count++;
        }
        return ans;
    }
};