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
    ListNode* vectorToList(const vector<int>& values){
        if(values.empty()) return NULL;

        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for(int i = 1; i < values.size(); i++) {
            current -> next = new ListNode(values[i]);
            current = current -> next;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        for(int i = 0; i < lists.size(); i++){
            ListNode* current = lists[i];
            while(current != NULL){
                values.push_back(current -> val);
                current = current -> next;
            }
        }
        sort(values.begin(), values.end());

        return vectorToList(values);
    }
};