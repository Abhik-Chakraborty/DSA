class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> seen(nums.begin(), nums.end());

        for (int num : nums) {
            if (num < k) return -1;
        }

        set<int, greater<int>> greaterThanK;
        for (int num : nums) {
            if (num > k) {
                greaterThanK.insert(num);
            }
        }

        int operations = 0;

        while (!greaterThanK.empty()) {
            int currentMax = *greaterThanK.begin(); 
            greaterThanK.erase(currentMax);

            if (!greaterThanK.empty()) {
                int next = *greaterThanK.begin();

                bool valid = true;
                for (int num : nums) {
                    if (num > next && num != currentMax) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) return -1;
                for (int &num : nums) {
                    if (num > next) num = next;
                }

                operations++;
            } else {
                bool valid = true;
                for (int num : nums) {
                    if (num > k && num != currentMax) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) return -1;

                for (int &num : nums) {
                    if (num > k) num = k;
                }

                operations++;
                break;
            }
        }

        for (int num : nums) {
            if (num != k) return -1;
        }

        return operations;
    }
};
