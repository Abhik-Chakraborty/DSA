class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int left = 0;
        int right = 0;
        while(left < s.size() && right < g.size()){
            if(s[left] >= g[right]){
                left++;
                right++;
            }else{
                left++;
            }
        }
        return right;
    }
};