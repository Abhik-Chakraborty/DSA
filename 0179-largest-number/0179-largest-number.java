class Solution {
    public String largestNumber(int[] nums) {
        
        String[] result = new String[nums.length];

        //converting from int to string
        for(int i = 0; i < nums.length; i++){
            result[i] = String.valueOf(nums[i]);
        }

        Arrays.sort(result, (a, b) -> (b + a).compareTo(a + b));

        if(result[0].equals("0")){
            return "0";
        }

        StringBuilder sb = new StringBuilder();

        for(String s : result){
            sb.append(s);
        }
        return sb.toString();
    }
}