class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> temp;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                temp.push_back(i);
            }
        }
        if(temp.size() < 2){
            return {-1, -1};
        }
        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 0; i < temp.size() - 1; i++) {
            int diff = temp[i + 1] - temp[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {temp[i], temp[i + 1]};
            }
        }

        return result;
    }
};