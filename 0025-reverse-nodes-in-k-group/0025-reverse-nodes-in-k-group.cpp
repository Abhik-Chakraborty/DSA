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
    ListNode* getKthNode(ListNode* temp , int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        ListNode* newHead = NULL;
        while(temp != NULL){
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode == NULL){
                if(prevLast != NULL){
                    prevLast -> next = temp;
                }
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            ListNode* reverseHead = reverseLinkedList(temp);
            if(newHead == NULL){
                newHead = reverseHead;
            }
            if(prevLast != NULL){
                prevLast -> next = reverseHead;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return newHead != NULL ? newHead : head;
    }
};