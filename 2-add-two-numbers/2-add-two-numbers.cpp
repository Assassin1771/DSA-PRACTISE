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
    
    ListNode* insert(ListNode* res, ListNode* temp)
    {
        ListNode* temp1=res;
        if(res==NULL)
        {
            res=temp;
            return res;
        }
        
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        
        temp1->next=temp;
        return res;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* res=NULL;
        
        int carry=0;
        while(l1!=NULL and l2!=NULL)
        {
            int x=0;
            
            if(carry)
            {
                x++;
                carry=0;
            }
            
            x+=l1->val+l2->val;
            
            if(x>9)
            {
                carry=1;
                x=x%10;
            }
            
            // cout<<l1->val<<" "<<l2->val<<" "<<x<<endl;
            
            l1=l1->next;
            l2=l2->next;
            
            ListNode* temp=new ListNode(x);
            
            // cout<<temp->val;
            res=insert(res,temp);
        }
        
        if(l1)
        {
            while(l1!=NULL)
            {
                int x=0;
            
                if(carry)
                {
                    x++;
                    carry=0;
                }
                
                x+=l1->val;
                
                if(x>9)
                {
                    carry=1;
                    x=x%10;
                }
                
                l1=l1->next;
                
                ListNode* temp=new ListNode(x);
                res=insert(res,temp);   
            }
        }
        
        if(l2)
        {
            while(l2!=NULL)
            {
                int x=0;
            
                if(carry)
                {
                    x++;
                    carry=0;
                }
                
                x+=l2->val;
                
                if(x>9)
                {
                    carry=1;
                    x=x%10;
                }
                
                l2=l2->next;
                
                ListNode* temp=new ListNode(x);
                res=insert(res,temp);   
            }
        }
        
        if(carry)
        {
            int x=carry;
            ListNode* temp=new ListNode(x);
            res=insert(res,temp);   
        }
        
        return res;
        
    }
};