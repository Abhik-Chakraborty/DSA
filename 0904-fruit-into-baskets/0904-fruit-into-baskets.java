class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();

        int n = fruits.length;
        int left = 0;
        int max = 0;

        for(int right = 0; right < n; right++){
            int fruit = fruits[right];

            if(map.containsKey(fruit)){
                map.put(fruit, map.get(fruit)+1);
            }
            else{
                map.put(fruit, 1);
            }
            while(map.size() > 2){
                int leftFruit = fruits[left];

                map.put(leftFruit, map.get(leftFruit) - 1);

                if(map.get(leftFruit) == 0){
                    map.remove(leftFruit);
                }
                left++;
            }
            int sizeWin = right - left + 1;

            if(sizeWin > max){
                max = sizeWin;
            }
        }
        return max;
    }
}