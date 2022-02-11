class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
        vector<int> next_great(n,-1);
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and nums2[s.top()] < nums2[i])
            {
                int x=s.top();
                s.pop();
                
                next_great[x]=i;
            }
            
            s.push(i);
        }
        
        // for(auto it:next_great)
        //     cout<<it<<" ";
        
        vector<int> res;
        for(int i=0;i<nums1.size();i++)
        {
            int x=nums1[i];
            auto it=find(nums2.begin(),nums2.end(),x);
            
            int ind=it-nums2.begin();
            int ind1=next_great[ind];
            
            if(ind1==-1)
                res.push_back(-1);
            
            else
                res.push_back(nums2[ind1]);
        }
        
        return res;
        
    }
};