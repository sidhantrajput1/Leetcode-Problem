class Solution {
    public boolean searchMatrix(int[][] a, int target) {
      int m = a.length, n = a[0].length;
      int st = 0, end = n * m - 1;

      while(st <= end) {
        int mid = st + (end - st) / 2;
        int midElt = a[mid/n][mid%n];

        if(midElt == target) return true;

        if(target < midElt) {
            end = mid - 1;
        } else {
            st = mid + 1;
        }
      }
      return false;
    }
}