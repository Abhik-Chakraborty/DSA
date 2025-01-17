class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int original0 = 0;
        int curr = original0;

        for (int i = 0; i < n - 1; i++) {
            curr = curr ^ derived[i];
        }

        if ((curr ^ derived[n - 1]) == original0) {
            return true; 
        }

       
        int original1 = 1;
        curr = original1;

        for (int i = 0; i < n - 1; i++) {
            curr = curr ^ derived[i];
        }

        if ((curr ^ derived[n - 1]) == original1) {
            return true; 
        }

        return false; 
    }
};