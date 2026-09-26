class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        if(indexDiff <= 0 || valueDiff < 0){
            return false;
        }

        TreeSet<Long> set = new TreeSet<>();

        for(int i = 0; i < nums.length; i++){
            long current = nums[i];

            long minimum = current - valueDiff;

            Long candidate = set.ceiling(minimum);

            if(candidate != null && candidate <= current + valueDiff){
                return true;
            }

            set.add(current);

            if(i >= indexDiff){
                set.remove((long) nums[i - indexDiff]);
            }
        }
        return false;
    }
}