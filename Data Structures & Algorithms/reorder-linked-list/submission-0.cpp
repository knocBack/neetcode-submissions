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
    ListNode* mergeLists(ListNode* even, ListNode* odd){
        ListNode* ans = NULL;
        ListNode* it = NULL;
        ListNode* node = NULL;
        int n = 0;
        while(even!=NULL || odd!=NULL){
            if(n%2==0){
                if(even){
                    node = even;
                    even = even->next;
                }
                else{
                    node = odd;
                    odd = odd->next;
                }
            }
            else{
                if(odd){
                    node = odd;
                    odd = odd->next;
                }
                else{
                    node = even;
                    even = even->next;
                }
            }
            node->next = NULL;
            if(it==NULL){
                ans = node;
                it = ans;
            }
            else{
                it->next = node;
                it = it->next;
            }
            n++;
        }
        return ans;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* cur = NULL;
        ListNode* tmp = NULL;
        while(head){
            tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
        }
        return cur;
    }

    vector<ListNode*> splitList(ListNode* head){
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* node = NULL;
        ListNode* it = NULL;
        ListNode* firstIt = NULL;
        ListNode* secondIt = NULL;

        int n = 0;
        it = head;
        while(it){
            n++;
            it = it->next;
        }
        int cut = 0;
        it = head;
        while(it){
            node = it;
            it = it->next;
            node->next = NULL;
            if(cut<=n/2){
                if(firstIt == NULL){
                    first = node;
                    firstIt = first;
                }
                else{
                    firstIt->next = node;
                    firstIt = firstIt->next;
                }
                // cout<<"Split first: "<<node->val<<'\n';
            }
            else{
                if(secondIt == NULL){
                    second = node;
                    secondIt = second;
                }
                else{
                    secondIt->next = node;
                    secondIt = secondIt->next;
                }
                // cout<<"Split second: "<<node->val<<'\n';
            }
            cut++;
        }
        return {first, second};
    }
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> splits = splitList(head);
        ListNode* first = splits[0];
        ListNode* second = reverseList(splits[1]);
        head = mergeLists(first, second);
    }
};
