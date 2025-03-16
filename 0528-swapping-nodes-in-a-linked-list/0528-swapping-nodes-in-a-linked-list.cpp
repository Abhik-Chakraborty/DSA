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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        ListNode* first = head;
        for(int i = 1; i < k; i++){
            first = first->next;
        }
        ListNode* second = head;
        for(int i = 1; i < length - k + 1; i++){
            second = second->next;
        }

        swap(first -> val, second -> val);
        return head;
        
    }
};