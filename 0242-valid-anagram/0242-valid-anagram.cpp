class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;

        unordered_map<char, int> mp;


        for (int i = 0; i < m; i++) {
            mp[s[i]]++; // count the frequency of each character and store im map
        }

        for (int i = 0; i < n; i++) {
            char ch = t[i];
            // if the ch is already present in mp then one decrease the count 
            // if the ch is 0 then erase in map 
            if (mp.find(ch) != mp.end()) {
                mp[ch]--;
                if(mp[ch] == 0) mp.erase(ch);
            }
            else return false;
        }

        if (mp.size() > 0) return false;

        return true;
    }
};