class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0;
        int right = s.size() - 1;
        int isPalindrome = true;

        while( left <= right) {
            if (s[left] != s[right]) isPalindrome = false;
            left++; right--;
        }
        if (isPalindrome) return 1;
        return 2;
    }
};