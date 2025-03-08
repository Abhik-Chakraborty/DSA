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
    ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head; 

        vector<int> arr;
        ListNode* temp = head;

        while (temp != NULL) {
            arr.push_back(temp->val);
            if (temp->next != NULL) {
                temp = temp->next->next;
            } else {
                break;
            }
        }

        ListNode* temp2 = head->next;
        while (temp2 != NULL) {
            arr.push_back(temp2->val);
            if (temp2->next != NULL) {
                temp2 = temp2->next->next;
            } else {
                break;
            }
        }

        int i = 0;
        ListNode* temp3 = head;
        while (temp3 != NULL) {
            temp3->val = arr[i++];
            temp3 = temp3->next;
        }

        return head;
    }
};