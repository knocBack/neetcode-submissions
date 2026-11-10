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
        int idx = -1;
        ListNode* ans = NULL;
        ListNode* it = NULL;
        while(!min_heap.empty()){
            idx = min_heap.top().second;
            min_heap.pop();
            if(ans == NULL){
                ans = lists[idx];
                it = ans;
            }
            else{
                it->next = lists[idx];
                it = it->next;
            }
            lists[idx] = lists[idx]->next;
            if(lists[idx] != NULL){
                min_heap.push({lists[idx]->val, idx});
            }
        }
        if(it != NULL)it->next = NULL;
        return ans;
    }
};
