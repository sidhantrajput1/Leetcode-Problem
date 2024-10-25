class Solution {
    public int[] productExceptSelf(int[] arr) {
        int n = arr.length;
        int[] right = new int[n];

        int prod = 1;

        for(int i = n - 1; i >= 0; i--) {
            prod = prod * arr[i];
            right[i] = prod;
        } 

        int[] ans = new int[n];

        int left = 1;

        for(int i = 0; i < n-1; i++) {
            int val = left * right[i+1];

            ans[i] = val;

            left = left * arr[i];

        }

        ans[n-1] = left;

        return ans;
    }
}