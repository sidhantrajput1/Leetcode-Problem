class Solution {
    public int lengthOfLastWord(String s) {
        String str = s.trim(); // remove extra space
        int count = 0;

        for(int i = str.length() - 1; i >= 0; i--) { // reverse loop
            if(str.charAt(i) != ' ') {
                count++;
            }
            else {
                break;
            }
        }

        return count;
    }
}