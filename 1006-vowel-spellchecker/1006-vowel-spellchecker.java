class Solution {
public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exact = new HashSet<>(Arrays.asList(wordlist));

        Map<String, String> caseMap = new HashMap<>();
        Map<String, String> vowelMap = new HashMap<>();

        for (String w : wordlist) {
            String lower = w.toLowerCase();
            caseMap.putIfAbsent(lower, w);
            vowelMap.putIfAbsent(devowel(lower), w);
        }

        String[] ans = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            if (exact.contains(q)) {                   
                ans[i] = q;
                continue;
            }

            String lower = q.toLowerCase();
            if (caseMap.containsKey(lower)) {         
                ans[i] = caseMap.get(lower);
                continue;
            }

            String key = devowel(lower);
            ans[i] = vowelMap.getOrDefault(key, "");  
        }

        return ans;
    }

    private String devowel(String s) {
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (isVowel(arr[i])) arr[i] = '*';
        }
        return new String(arr);
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
