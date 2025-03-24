class Solution {
public:
    void reverse(string& word, int left, int right) {
        while (left < right) {
            int temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left++; right--;
        }
    }
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);

        if (idx >= 0 && idx < word.size())  {
            reverse(word, 0, idx);
        }
        
        return word;
    }
};