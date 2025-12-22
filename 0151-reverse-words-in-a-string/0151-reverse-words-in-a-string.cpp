class Solution {
public:
    // Convert string into array of words
    vector<string> convertInArr(string s) {
        vector<string> arr;
        string word = "";

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    arr.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) {
            arr.push_back(word);
        }

        return arr;
    }

    // Reverse vector<string>
    void reverseVector(vector<string>& arr, int st, int end) {
        while (st < end) {
            string temp = arr[st];
            arr[st] = arr[end];
            arr[end] = temp;
            st++;
            end--;
        }
    }

    string reverseWords(string s) {
        // Step 1: Convert string to array
        vector<string> arr = convertInArr(s);

        // Step 2: Reverse the array
        reverseVector(arr, 0, arr.size() - 1);

        // Step 3: Convert array back to string
        string ans = "";
        for (string &word : arr) {
            ans += word + " ";
        }

        // Remove trailing space
        ans.pop_back();

        return ans;
    }
};
