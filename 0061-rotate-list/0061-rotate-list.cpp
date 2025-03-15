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
    ListNode* findNthNode(ListNode* temp, int k){
        int count = 1;
        while(temp != NULL){
            if(count == k) return temp;
            count++;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0 ) return head;
        int length = 1;
        ListNode* tail = head;
        while(tail -> next != NULL){
            length++;
            tail = tail->next;
        }
        if(k % length == 0) return head;
        k = k % length;

        tail -> next = head;
        ListNode* newTail = findNthNode(head, length - k);
        head = newTail->next;
        newTail -> next = NULL;
        return head;
    }
};