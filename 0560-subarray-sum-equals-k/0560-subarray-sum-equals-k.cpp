class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            map<int, int> preSumMap;
            int sum = 0; 
            int count = 0;  

            preSumMap[0] = 1; 

            for (int i = 0; i < n; i++) {
                sum += nums[i];  

            
                if (preSumMap.find(sum - k) != preSumMap.end()) {
                    count += preSumMap[sum - k];  
                }

                
                preSumMap[sum]++;
            }

            return count;
        }
};