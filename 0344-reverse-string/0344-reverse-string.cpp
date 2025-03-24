class Solution {
public:
    void reverse(vector<char>& s, int left, int right) {
        while (left < right) {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++; right--;
        }
    }
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
};