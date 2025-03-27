/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getListSize(ListNode* head){
        int size = 0;
        ListNode* current = head;
        while(current != NULL){
            size++;
            current = current -> next;
        }
        return size;
    }

    TreeNode* sortedListToBSTHelper(ListNode*& head, int size) {
        if(size <= 0){
            return NULL;
        }
        TreeNode* left = sortedListToBSTHelper(head, size / 2);
        
        TreeNode* root = new TreeNode(head -> val);
        root -> left = left;

        head = head -> next;
        root -> right = sortedListToBSTHelper(head, size - size / 2 - 1);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = getListSize(head);
        return sortedListToBSTHelper(head, size);
    }

    void inOrder(TreeNode* root, vector<int>& ans){
        if(root != NULL){
            inOrder(root -> left, ans);
            ans.push_back(root -> val);
            inOrder(root -> right, ans);
        }
    }
};