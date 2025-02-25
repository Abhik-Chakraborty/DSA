class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        //putting k element to the temp array
        vector<int>temp;
        for(int i = n - k; i < n; i++){
            temp.push_back(nums[i]);
        }

        //shifting
        for(int i = n-1; i >= k; i--){
            nums[i] = nums[i - k];
        }

        //putting all back 
        for(int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};