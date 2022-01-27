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
    
    ListNode* createLL(ListNode* res,int x)
    {
        ListNode *final=new ListNode(x);
        
        if(res==NULL)
        {
            res=final;
            return res;
        }
        
        ListNode* temp=res;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        
        temp->next=final;
        final->val=x;
        final->next=NULL;
        
        return res;
        
    }
    
    ListNode* oddEvenList(ListNode* head) {
        
        vector<int> odd;
        vector<int> even;
        
        int flag=1;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(flag==1)
            {
                odd.push_back(temp->val);
                flag=0;
            }
            
            else
            {
                even.push_back(temp->val);
                flag=1;
            }
        
            temp=temp->next;
        }
        
        ListNode* res;
        for(int i=0;i<odd.size();i++)
        {
            res=createLL(res,odd[i]);
        }
        
        for(int i=0;i<even.size();i++)
        {
            res=createLL(res,even[i]);
        }
        
        return res;
        
    }
};