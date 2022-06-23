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
        
        ListNode* first=head, *second=head;
        
        int temp=n;
        while(temp--)
        {
            first=first->next;
        }
        
        if(first==NULL)
        {
            ListNode* root=head;
            
            head=head->next;
            delete(root);
            
            return head;
        }
        
        while(first->next)
        {
            second=second->next;
            first=first->next;
        }
        
        ListNode* deleteNode=second->next;
        
        second->next=deleteNode->next;
        delete(deleteNode);
        
        return head;
        
    }
};