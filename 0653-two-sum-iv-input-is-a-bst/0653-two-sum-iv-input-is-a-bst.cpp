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
    void inOrder(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }
        inOrder(root->left, arr);
        arr.push_back(root->val);
        inOrder(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root, arr); // we get the sorted array here. 
        for(int i = 0; i < arr.size(); i++){
            int sum = 0;
            for(int j = i + 1; j < arr.size(); j++){
                sum = arr[i] + arr[j];
                if(sum == k){
                    return true;
                }
            }
        }
        return false;

    }
};