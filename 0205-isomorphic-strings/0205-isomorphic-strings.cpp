class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp1;
        map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            int ch1 = s[i];
            int ch2 = t[i];

            if (mp1.count(ch1)) {
                if (mp1[ch1] != ch2) {
                    return false;
                }
            } else
                mp1[ch1] = ch2;

            if (mp2.count(ch2)) {
                if (mp2[ch2] != ch1) {
                    return false;
                }
            } else
                mp2[ch2] = ch1;
        }
        return true;
    }
};