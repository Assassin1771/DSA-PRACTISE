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
    
    ListNode*  createLL(ListNode* head,int x)
    {
        ListNode* val=new ListNode(x);
        if(head==NULL)
        {
            head=val;
            return head;
        }
        
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=val;
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        vector<int> v;
        
        ListNode* temp=list1;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        temp=list2;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        sort(v.begin(),v.end());
        
        ListNode* head=NULL;
        for(int i=0;i<v.size();i++)
        {
            head=createLL(head,v[i]);
        }
        
        return head;
        
    }
};