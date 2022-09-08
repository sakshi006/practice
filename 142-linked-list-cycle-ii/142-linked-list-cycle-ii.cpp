/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pos= NULL;
        
        if(!head)
            return pos;
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        bool iscycle=false;
        while(fast!=NULL && fast->next !=NULL)
        {
            if(slow==fast)
            {
                iscycle=true;
                break;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!iscycle)
            return pos;
        
        slow=head;
        while(slow!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};