class Solution {
    public int longestOnes(int[] nums, int k) {
        int zeroCount = 0;
        int maxLength = 0;
        int i = 0;
        for(int j = i; j < nums.length; j++){
            if(nums[j] == 0){
                zeroCount++;
            }
            if(zeroCount > k){
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
            }
            int length = j - i + 1;
            if(length > maxLength){
                maxLength = length;
            }
        }
        return maxLength;
    }
}