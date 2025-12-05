class Solution {
public:
    // ye charchter check karta hai, ki yo vowel hai ya nhi  
    bool isVowel(char c) {
        c = tolower(c);
        return (c =='a' || c == 'e' || c == 'i' || c == 'o' || c =='u');
    }

    string reverseVowels(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i < j) {
            //  agr s[i] ki value vowel nhi hai to i++ ko badhate raho
            while(i < j && !isVowel(s[i])) i++; 
            //  agr s[j] ki value vowel nhi hai to j-- ko ghathe raho
            while(i < j && !isVowel(s[j])) j--;

            if (i < j) {
                swap(s[i], s[j]);
                i++; 
                j--; 
            }
        }

        return s;
    }
};
