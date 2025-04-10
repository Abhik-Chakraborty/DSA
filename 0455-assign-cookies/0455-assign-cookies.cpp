class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        int count = 0;
        while(left < s.size() && right < g.size()){
            if(s[left] >= g[right]){
                count++;
                left++;
                right++;
            }else{
                left++;
            }
        }
        return count;
    }
};