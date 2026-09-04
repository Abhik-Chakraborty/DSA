class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();

        int i = 0;
        int maxLength = 0;

        for(int j = 0; j < s.length(); j++){
            char ch = s.charAt(j);

            if(map.containsKey(ch)){
                int previousIndex = map.get(ch) + 1;

                if(previousIndex > i){
                    i = previousIndex;
                }
            }
            map.put(ch, j);

            int currentLength = j - i + 1;
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
        }
        return maxLength;
    }
}