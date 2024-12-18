class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];

        answer[n-1] = prices[n-1];

        for(int i = 0; i < n; i++) {
            for(int j = i + 1 ; j < n; j++) {
                if(j > i && prices[j] <= prices[i]) {
                    answer[i] = (prices[i] - prices[j]);
                    break;
                } else {
                    answer[i] = prices[i];
                }
            }
        }
        return answer;
    }
}