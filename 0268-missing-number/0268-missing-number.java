class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;

        int sum = 0;
        for(int i = 0; i < arr.length; i++) {
            sum = sum  + arr[i];
        }
        int actualSum = (arr.length * (arr.length + 1))/2;
        int missingNum = actualSum - sum;

        return missingNum;
    }
}