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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* temp1 = q1.front();
            TreeNode* temp2 = q2.front();
            q1.pop();
            q2.pop();

            if(temp1 -> val != temp2 -> val){
                return false;
            }
            if(temp1 -> left && temp2 -> left){
                q1.push(temp1->left);
                q2.push(temp2->left);
            }
            else if(temp1 -> left || temp2 -> left){
                return false;
            }
            if(temp1 -> right && temp2 -> right){
                q1.push(temp1->right);
                q2.push(temp2->right);
            }
            else if(temp1 -> right || temp2 -> right){
                return false;
            }
        }
        return q1.empty() && q2.empty();
    }
};