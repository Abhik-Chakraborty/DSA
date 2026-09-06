class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        Map<Character, Integer> s1Map = new HashMap<>();
        Map<Character, Integer> windowMap = new HashMap<>();

        for (char ch : s1.toCharArray()) {
            s1Map.put(ch, s1Map.getOrDefault(ch, 0) + 1);
        }
        int windowSize = s1.length();

        for (int right = 0; right < s2.length(); right++) {
            char currentChar = s2.charAt(right);
            windowMap.put(
                currentChar,
                windowMap.getOrDefault(currentChar, 0) + 1
            );
            if (right >= windowSize) {
                int left = right - windowSize;
                char leftChar = s2.charAt(left);
                windowMap.put(
                    leftChar,
                    windowMap.get(leftChar) - 1
                );
                if (windowMap.get(leftChar) == 0) {
                    windowMap.remove(leftChar);
                }
            }
            if (right >= windowSize - 1) {
                if (s1Map.equals(windowMap)) {
                    return true;
                }
            }
        }
        return false;
    }
}