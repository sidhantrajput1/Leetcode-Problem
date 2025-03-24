class Solution {
public:
    void reverse(string& s, int left, int right) {
        while ( left < right ) {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++; right--;
        }
    }
    string reverseWords(string s) {
        int st = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, st, i-1);
                st = i + 1;
            }
        }
        return s;
    }
};