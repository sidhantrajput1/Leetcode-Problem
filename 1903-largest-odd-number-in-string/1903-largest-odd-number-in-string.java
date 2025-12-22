class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();

        for (int i = n - 1; i >= 0; i--) {
            int digit = num.charAt(i) - '0';

            // Check if digit is odd
            if (digit % 2 == 1) {
                return num.substring(0, i + 1);
            }
        }
        return "";
    }
}