class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int i = 0;
        int j = i;
        int count = 0;
        int sum = 0;

        while(j < arr.length){
            sum = sum + arr[j];

            int windowSize = j - i + 1;
            if(windowSize < k){
                j++;
            }
            else if (windowSize == k){
                if(sum >= threshold * k){
                    count++;
                }
                sum = sum - arr[i];
                i++;
                j++;
            }
        }
        return count;
    }
}