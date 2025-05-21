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
    int minDiff = INT_MAX;
    TreeNode* prev = NULL;
    void inOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inOrder(root->left);

        if(prev != NULL){
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;

        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};