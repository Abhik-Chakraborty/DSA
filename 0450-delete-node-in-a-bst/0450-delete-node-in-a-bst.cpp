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
    TreeNode* getMin(TreeNode* node){
        while(node && node -> left){
            node = node -> left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(key < root -> val){
            root -> left = deleteNode(root -> left, key);
        }
        else if(key > root -> val){
            root -> right = deleteNode(root -> right, key);
        }
        else{
            //Not found
            if(!root -> left){
                TreeNode* rightChild = root -> right;
                delete root;
                return rightChild;
            }
            else if(!root -> right){
                TreeNode* leftChild = root -> left;
                delete root;
                return leftChild;
            }
            else{
                //node with two children
                TreeNode* minLargerNode = getMin(root->right);
                root->val = minLargerNode->val;
                root -> right = deleteNode(root->right, minLargerNode->val);
            }
        }
        return root;
    }
};