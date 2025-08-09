class Solution {
public:
    unordered_set<string> st; // dictionary words
    int n; 
    int t[305]; // memo table

    bool solve(int idx, string &s) {
        if (idx == n) return true; // reached end → valid segmentation

        if (t[idx] != -1) return t[idx]; // already computed

        string temp = "";
        for (int l = idx; l < n; l++) {
            temp.push_back(s[l]); // add one char

            // if prefix exists in dictionary and rest of the string is valid
            if (st.find(temp) != st.end() && solve(l + 1, s)) {
                return t[idx] = true;
            }
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
