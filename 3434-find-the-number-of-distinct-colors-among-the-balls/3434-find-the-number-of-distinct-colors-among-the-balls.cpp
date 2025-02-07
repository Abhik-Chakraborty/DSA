class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors;  
        unordered_map<int, int> colorCount;  
        vector<int> result;
        int distinctColorCount = 0;  

        for (auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ballColors.find(ball) != ballColors.end()) {
                int oldColor = ballColors[ball];
                if (oldColor != color) {
                    colorCount[oldColor]--;
                    if (colorCount[oldColor] == 0) {
                        distinctColorCount--;  
                    }
                    ballColors[ball] = color;
                    if (colorCount[color] == 0) {
                        distinctColorCount++;  
                    }
                    colorCount[color]++;
                }
            } else {
                ballColors[ball] = color;
                if (colorCount[color] == 0) {
                    distinctColorCount++;  
                }
                colorCount[color]++;
            }

            result.push_back(distinctColorCount);
        }

        return result;
    }
};