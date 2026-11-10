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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode *it = NULL, *prev = NULL;
        it = head;
        while(it && ++l)it = it->next;
        int idx = l-n;
        it = head;
        while(idx > 0){
            prev = it;
            it = it->next;
            idx--;
        }
        if(idx == 0){
            if(prev == NULL){
                head = head->next;
            }
            else{
                prev->next = it->next;
            }
        }
        return head;
    }
};
