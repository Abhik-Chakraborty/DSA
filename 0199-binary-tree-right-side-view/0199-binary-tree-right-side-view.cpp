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
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> res;
        // recursion(root, 0, res);
        // return res;

        //iterative method here
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            res.push_back(temp->val);
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr -> right != NULL) q.push(curr->right);
                if(curr -> left != NULL) q.push(curr -> left);
            }
        }
        return res;
    }
    // void recursion(TreeNode* root, int level, vector<int>& res){
    //     if(root == NULL) return;
    //     if(res.size() == level) res.push_back(root->val);
    //     recursion(root->right, level + 1, res);
    //     recursion(root->left, level + 1, res); 
    // }
};