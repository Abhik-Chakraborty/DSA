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
    void preOrderTraverse(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            return;
        }
        arr.push_back(root->val);
        preOrderTraverse(root->left, arr);
        preOrderTraverse(root->right, arr);
    }
    void sumOfCurrentNumber(vector<int>& arr, vector<int>& greaterSum){
        greaterSum.assign(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            int sum = 0;
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] > arr[i]){
                    sum += arr[j];
                }
            }
            greaterSum[i] += sum;
        }
    }
    void preOrderFill(TreeNode* root, vector<int>& originalValues, vector<int>& greaterSum){
        if(root == NULL){
            return;
        }
        for(int i = 0; i < originalValues.size(); i++){
            if(originalValues[i] == root->val){
                root->val = greaterSum[i];
                break;
            }
        }
        preOrderFill(root -> left, originalValues, greaterSum);
        preOrderFill(root -> right, originalValues, greaterSum);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        vector<int> originalValues;
        vector<int> greaterSum;
        preOrderTraverse(root, originalValues);
        sumOfCurrentNumber(originalValues, greaterSum);
        preOrderFill(root, originalValues, greaterSum);
        return root;
    }
};