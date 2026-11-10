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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)min_heap.push({lists[i]->val, i});
        }
        pair<int,int> top;
        ListNode* ans = NULL;
        ListNode* it = NULL;
        while(!min_heap.empty()){
            top = min_heap.top();
            min_heap.pop();
            if(ans == NULL){
                ans = lists[top.second];
                it = ans;
            }
            else{
                it->next = lists[top.second];
                it = it->next;
            }
            lists[top.second] = lists[top.second]->next;
            if(lists[top.second] != NULL){
                min_heap.push({lists[top.second]->val, top.second});
            }
        }
        if(it != NULL)it->next = NULL;
        return ans;
    }
};
