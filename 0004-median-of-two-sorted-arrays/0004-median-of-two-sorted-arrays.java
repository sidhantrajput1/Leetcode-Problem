class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] ans = mergedSortedArray(nums1,nums2);

        if(ans.length % 2 == 0) {
            double ans2 = (double)(ans [ans.length/2]  + ans [ans.length/2 -1])/2;
            return ans2;
        } else {
            double ans2 = (double) ( ans [ans.length/2]);
            return ans2;
        }

    }
    static int[] mergedSortedArray(int[] arr1, int[] arr2) {
        int n1 = arr1.length;
        int n2 = arr2.length;

        int[] mergedArray = new int[n1 + n2];
        int i = 0, j = 0, k = 0;

        while(i < n1 && j < n2) {
            if(arr1[i] <= arr2[j]) {
                mergedArray[k++] = arr1[i++];                
            } else {
                mergedArray[k++] = arr2[j++];
            }
        }

        while( i < n1) {
            mergedArray[k++] = arr1[i++];
        }

        while( j < n2) {
            mergedArray[k++] = arr2[j++];
        }


        return mergedArray;
    }
}