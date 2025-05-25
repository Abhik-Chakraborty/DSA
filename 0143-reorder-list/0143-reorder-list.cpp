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
    void reorderList(ListNode* head) {
        //1st step -> find the mid;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next; // we have our mid
        }

        //2nd step -> from mid reverse
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow -> next = NULL;

        //3rd step -> joining;
        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};