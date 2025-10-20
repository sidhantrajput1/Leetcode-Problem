class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int X = 0;
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == "--X" || op[i] == "X--") {
                X--;
            } else if (op[i] == "++X" || op[i] == "X++") {
                X++;
            }
        }

        return X;
    }
};