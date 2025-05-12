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
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
private:
    void inOrder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inOrder(root -> left);

        if(prev != NULL && (root -> val < prev -> val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inOrder(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inOrder(root);
        if(first && last){
            swap(first -> val, last -> val);
        }
        else if(first && middle){
            swap(first -> val, middle -> val);
        }
    }
};