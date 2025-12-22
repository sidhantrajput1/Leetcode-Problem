class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        // if (num[n-1] == '1' || num[n-1] == '3' || num[n-1] == '5' || num[n-1] == '7' || num[n-1] == '9') return num;
        // if (num[n-1] % 2 != 0) return num;
        // return "";

        for (int i = n - 1; i >= 0; i--) {
            if (num[i] % 2 != 0) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};