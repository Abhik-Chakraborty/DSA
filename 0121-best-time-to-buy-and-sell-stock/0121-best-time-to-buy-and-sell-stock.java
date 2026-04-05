class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;

        int profit = 0;
        int buy_price = prices[0];
        for(int i = 0; i<n; i++){
            int current_profit = prices[i]-buy_price;

            if(current_profit > profit){
                profit = current_profit;
            }
            if(prices[i] < buy_price){
                buy_price=prices[i];
            }
        }
        return profit;
    }
}