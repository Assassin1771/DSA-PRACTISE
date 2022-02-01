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
    int pairSum(ListNode* head) {
        
        vector<int> v;
        
        ListNode* temp=head;
        while(temp)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        int maxx=0;
        for(int i=0;i<v.size()/2;i++)
        {
            // cout<<v[i]<<" "<<v[v.size()-i-1];
            int x=(v[i]+v[v.size()-i-1]);
            maxx=max(maxx,x);
        }
        
        return maxx;
        
    }
};