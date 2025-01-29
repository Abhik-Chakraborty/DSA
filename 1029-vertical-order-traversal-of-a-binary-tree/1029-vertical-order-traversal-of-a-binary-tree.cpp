/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> columnMap; 
        queue<pair<TreeNode*, pair<int, int>>> q; 
        
        if (root) {
            q.push({root, {0, 0}}); 
        }
        
        while (!q.empty()) {
            auto [node, position] = q.front();
            q.pop();
            int row = position.first;
            int col = position.second;
            
            columnMap[col].push_back({row, node->val});
            
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& [col, nodes] : columnMap) {
            sort(nodes.begin(), nodes.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first < b.first;
            });
            
            vector<int> colResult;
            for (auto& [row, value] : nodes) {
                colResult.push_back(value);
            }
            result.push_back(colResult);
        }
        
        return result;
    }
};