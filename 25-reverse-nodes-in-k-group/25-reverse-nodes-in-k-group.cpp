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
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        int ct = 0;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy, *nextnode = dummy, *prev = dummy;
        
        while(curr->next)
        {
            curr= curr->next;
            ct++;
        }
        
        
        while(ct>=k)
        {
            curr = prev->next;
            nextnode = curr->next;
            
            for(int i = 1;i<k;i++)
            {
                curr->next = nextnode->next;
                nextnode->next = prev->next;
                prev->next = nextnode;
                nextnode = curr->next;
            }
            
            prev = curr;
            ct-=k;
        }
        return dummy->next;
    }
};