class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer, Integer> prefixCount = new HashMap<>();

        prefixCount.put(0, 1);

        int oddCount = 0;
        int result = 0;

        for(int num : nums){
            if(num % 2 != 0){
                oddCount++;
            }
            int required = oddCount - k;

            result += prefixCount.getOrDefault(required, 0);

            prefixCount.put(oddCount, prefixCount.getOrDefault(oddCount, 0) + 1);
        }
        return result; 
    }
}