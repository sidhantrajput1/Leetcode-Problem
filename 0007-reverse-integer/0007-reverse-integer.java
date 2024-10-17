class Solution {
    public static int reverse(int x) {
        int reverse = 0;
        while(x != 0) {
            int remender = x % 10;
            if(reverse > Integer.MAX_VALUE/10 || (reverse ==  Integer.MAX_VALUE/10 && remender > 7)) {
                return 0;
            }
            if(reverse < Integer.MIN_VALUE/10 || (reverse ==  Integer.MIN_VALUE/10 && remender < -8)) {
                return 0;
            }
            reverse = reverse * 10 + remender;
            x = x / 10;
            
        }

        System.out.println("Max val is:  "+Integer.MAX_VALUE) ;
        System.out.println("Min val is:  "+Integer.MIN_VALUE) ;

        


        return reverse;
    }
    public static void main(String[] args) {
        int x = 123;

        int result = reverse(x);
        System.out.print(result);
    }
}