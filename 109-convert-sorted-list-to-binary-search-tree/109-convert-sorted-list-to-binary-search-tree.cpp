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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int sizeOfList(ListNode* head)
    {
        if(!head)
            return 0;
        
        ListNode* curr=head;
        int count=1;
        
        while(curr->next)
        {
            curr=curr->next;
            count++;
        }
        
        return count;
    }
    
    int findMiddleList(ListNode* head, int ind)
    {
        ListNode* curr=head;
        int count=0;
        
        while(curr->next)
        {
            if(ind==count)
                return curr->val;
            
            curr=curr->next;
            count++;
        }
        
        return curr->val;
    }
    
    TreeNode* constructBST(int low, int high, ListNode* head)
    {
        if(low>=high)
            return NULL;
        
        int mid=(low+high)/2;
        int mid_value=findMiddleList(head,mid);
        
        TreeNode* root=new TreeNode(mid_value);
        
        root->left=constructBST(low,mid,head);
        root->right=constructBST(mid+1,high,head);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        int low=0,high=0;
        high=sizeOfList(head);
        
        if(high==0)
            return NULL;
        
        return constructBST(low,high,head);
        
    }
};