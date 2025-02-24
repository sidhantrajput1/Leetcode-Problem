class Solution {
    public int vowelStrings(String[] words, int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++) {
            int st = words[i].charAt(0);
            int end = words[i].charAt(words[i].length()-1);

            if(st == 'a' || st == 'e' || st == 'i' || st == 'o' || st == 'u') {
                if(end == 'a' || end == 'e' || end == 'i' || end == 'o' || end == 'u') count++;
            }
        }
        return count;
    }
}