class Solution {
public:
    string reverseWords(string s) {
        string temp;
        vector<string> words;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                temp += s[i];
            }
            else{
                if(!temp.empty()){
                    words.push_back(temp);
                    temp = "";
                }
            }
        }
        if(!temp.empty()){
            words.push_back(temp); // words = the,sky,is,blue
        }
        string result;
        for(int i = words.size() - 1; i >= 0; i--){
            result += words[i];

            if(i > 0){
                result += " ";
            }

        }
        return result;
    }
};