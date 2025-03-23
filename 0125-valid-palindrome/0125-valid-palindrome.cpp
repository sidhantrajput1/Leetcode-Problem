class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {

            // skip non-alpha numeric characters for i and j
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            
            // compare the characters , ignoring case
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
            i++;
            j--;
        }

        return true;
    }
};