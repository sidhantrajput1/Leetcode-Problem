class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        System.out.println(n);

        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum = sum  + arr[i];
        } 
        System.out.println(sum);

        int actualSum = (arr.length * (arr.length + 1))/2;
        System.out.println(actualSum);

        int missingNum = actualSum - sum;
        System.out.println(missingNum);

        return missingNum;
    }
}