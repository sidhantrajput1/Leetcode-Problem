class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];

        for(int i = 0; i < n; i++) {
            for(int j = i + 1 ; j < n; j++) {
                if(j > i && prices[j] <= prices[i]) {
                    answer[i] = (prices[i] - prices[j]);
                    break;
                } else {
                    answer[i] = prices[i];
                }
            }
            if(i == n - 1) {
                answer[i] = prices[i];
            }
        }
        return answer;
    }
}