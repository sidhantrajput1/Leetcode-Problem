class Solution {
    public int countDigits(int num) {
        int copy = num;
        int digit = 0;
        int count = 0;
        while(num != 0) {
            digit = num % 10;
            num = num / 10;
            if(copy%digit == 0) {
                count++;
            }
        }
        return count;
    }
}