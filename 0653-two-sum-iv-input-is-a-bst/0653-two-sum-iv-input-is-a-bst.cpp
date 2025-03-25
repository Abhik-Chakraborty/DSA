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
        int i = 0;
        int j = arr.size() - 1;
        while(i < j){
            int sum = arr[i] + arr[j];
            if(sum > k){
                j--;
            }
            else if (sum < k){
                i++;
            }
            else if (sum == k){
                return true;
            }
        }
        return false;
    }
};