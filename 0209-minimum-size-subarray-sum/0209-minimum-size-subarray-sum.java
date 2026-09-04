class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum = 0;
        int i = 0;
        int minLength = Integer.MAX_VALUE;

        for(int j = 0; j < nums.length; j++){
            sum += nums[j];

            while(sum >= target){
                int length = j - i + 1;
                if(length < minLength){
                    minLength = length;
                }
                sum -= nums[i];
                i++;
            }
        }
        if(minLength == Integer.MAX_VALUE){
            minLength = 0;
        }
        return minLength;
    }
}