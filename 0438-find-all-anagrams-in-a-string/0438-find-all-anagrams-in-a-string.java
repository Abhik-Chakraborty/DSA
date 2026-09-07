class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();

        int[] pFreq = new int[26];
        int[] windowFreq = new int[26];

        for(int i = 0; i < p.length(); i++){
            pFreq[p.charAt(i) - 'a']++;
        }
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            windowFreq[s.charAt(right) - 'a']++;

            if(right - left + 1 > p.length()){
                windowFreq[s.charAt(left) - 'a']--;
                left++;
            }

            if(right - left + 1 == p.length()){
                boolean same = true;

                for(int i = 0; i < 26; i++){
                    if(pFreq[i] != windowFreq[i]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    result.add(left);
                }
            }
        }
        return result;
    }
}