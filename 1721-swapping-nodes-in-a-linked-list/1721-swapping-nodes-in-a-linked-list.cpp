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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n=0;
        
        ListNode* temp=head;
        
        while(temp)
        {
            temp=temp->next;
            n++;
        }
        
        ListNode *x=NULL, *y=NULL;
        int i=1;
        
        temp=head;
        while(temp)
        {
            if(i==k)
            {
                x=temp;
            }
            
            if(i==n-k+1)
            {
                y=temp;
            }
            
            temp=temp->next;
            i++;
        }
        
        int swap=x->val;
        x->val=y->val;
        y->val=swap;
        
        return head;
        
        
    }
};