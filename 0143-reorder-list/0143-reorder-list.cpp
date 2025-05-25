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
        if(!head || !head->next || !head->next->next){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow -> next;
        while(curr){
            ListNode* nextTemp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextTemp;
        }
        slow -> next = NULL; //split the list


        ListNode* first = head;
        ListNode* second = prev;
        while(second){
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }
    }

};