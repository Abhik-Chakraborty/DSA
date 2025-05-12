class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueIntegers;

        for(int i = 0; i < digits.size(); i++){
            for(int j = 0; j < digits.size(); j++){
                for(int k = 0; k < digits.size(); k++){
                    if(i != j && j != k && k != i){
                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];

                        if(a == 0) continue;
                        if(c % 2 != 0) continue; // must be even right !

                        int number = a * 100 + b * 10 + c;
                        uniqueIntegers.insert(number);
                    }
                }
            }
        }
        vector<int> result(uniqueIntegers.begin(), uniqueIntegers.end());
        return result;
    }
};