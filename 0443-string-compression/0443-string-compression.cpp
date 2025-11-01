class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int index = 0;
        int i = 0;
        while (i < n) {

            char curr_char = chars[i];
            int count = 0;

            while ( i < n && curr_char == chars[i]) {
                count++;
                i++;
            }

            chars[index] = curr_char;
            index++;

            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[index] = c;
                    index++;
                }
            }
        }

        return index;
    }
};