class Solution {
    public int maximumSum(int[] nums) {
        int[] best = new int[82];

        int ans = -1;

        for(int num : nums){
            int sum = digitSum(num);

            if(best[sum] != 0){
                ans = Math.max(ans, best[sum] + num);
            }
            best[sum] = Math.max(best[sum], num);
        }
        return ans;
    }
    private int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}

//rough work : 
/**
i != j
the sum of digits of the number nums[i] is equal to that of nums[j].

 */