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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL){
            return result;
        }
        dfs(root, "",result);
        return result;
    }
    void dfs(TreeNode* root, string path, vector<string>& result){
        if(root == NULL){
            return;
        }
        if(!path.empty()){
            path += "->";
        }
        path += to_string(root->val);

        if(root -> left == NULL && root -> right == NULL){
            result.push_back(path);
            return;
        }

        dfs(root -> left, path, result);
        dfs(root -> right, path, result);
    }
};