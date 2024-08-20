class Solution {
    public static int reverse(int x) {
        int reverse = 0;
        while(x != 0) {
            int remender = x % 10;
            if(reverse > Integer.MAX_VALUE/10 || reverse < Integer.MIN_VALUE/10) {
                return 0;
            }
            reverse = reverse * 10 + remender;
            x = x / 10;
            
        }
        return reverse;
    }
    public static void main(String[] args) {
        int x = 123;

        int result = reverse(x);
        System.out.print(result);
    }
}