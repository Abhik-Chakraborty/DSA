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
    pair<int, TreeNode*> dfs(TreeNode* root){
        if(root == NULL){
            return {0, NULL};
        }

        auto left = dfs(root -> left);
        auto right = dfs(root -> right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        TreeNode* leftLCA = left.second;
        TreeNode* rightLCA = right.second;

        if(leftDepth > rightDepth){
            return {leftDepth + 1, leftLCA};
        }
        else if(rightDepth > leftDepth){
            return {rightDepth + 1, rightLCA};
        }
        else{
            if(leftLCA == rightLCA){
                return {leftDepth + 1, root};
            }
            else{
                return {leftDepth + 1, root};
            }
        }


        
    } 
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};