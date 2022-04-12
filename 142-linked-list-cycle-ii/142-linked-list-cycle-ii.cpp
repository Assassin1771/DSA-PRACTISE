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
        
        ListNode *slow=head, *fast=head;
        
        if(!head)
            return NULL;
        
        if(slow->next==NULL)
            return NULL;
        
        while(fast and fast->next)
        {            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                break;
        }
                
        if(slow!=fast)
            return NULL;
        
        slow = head;
        while(slow  != fast){
            fast = fast->next;slow = slow->next;
        }
        return slow;
        
    }
};