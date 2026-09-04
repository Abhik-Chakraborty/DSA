class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double avg = 0;
        int sum = 0;
        double maxAvg = Integer.MIN_VALUE;

        for(int i = 0; i < k; i++){
            sum = sum + nums[i];
        }
        maxAvg = sum / (double)k;

        for(int i = k; i < nums.length; i++){
            sum += nums[i];
            sum -= nums[i - k];
            avg = sum / (double) k; 
            if(maxAvg < avg){
                maxAvg = avg;
            }
        }
        return maxAvg;
    }
}