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
    
    int sizeOfList(ListNode* head)
    {
        int count=0;
        
        while(head)
        {
            head=head->next;
            count++;
        }
        
        return count;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        int length=sizeOfList(head);
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* prev=dummy, *curr, *next;
        
        while(length>=k)
        {
            curr=prev->next;
            next=curr->next;
            
            for(int i=1;i<k;i++)
            {
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
            }
            
            prev=curr;
            length-=k;
        }
        
        return dummy->next;
        
    }
};