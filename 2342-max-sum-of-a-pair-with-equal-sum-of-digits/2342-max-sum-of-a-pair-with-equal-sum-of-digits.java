class Solution {
    public int maximumSum(int[] nums) {
        // int[] best = new int[82];
        Map<Integer, Integer> map = new HashMap<>();

        int ans = -1;

        for(int num : nums){
            int sum = digitSum(num);

            if(map.containsKey(sum)){
                ans = Math.max(ans, map.get(sum) + num);
            }
            map.put(sum, Math.max(map.getOrDefault(sum, 0), num));
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