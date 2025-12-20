class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int r = 0; // read pointer
        int w = 0; // write pointer

        while (r < n) {
            char curr = chars[r];
            int count = 0;

            while (r < n && curr == chars[r]) {
                count++;
                r++;
            }

            chars[w] = curr;
            w = w + 1;

            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[w++] = c;
                }
            }
        }

        return w;
    }
};