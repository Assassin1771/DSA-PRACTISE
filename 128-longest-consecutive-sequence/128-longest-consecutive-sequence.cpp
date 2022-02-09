class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        sort(begin(nums),end(nums));
        
        if(n==0)
            return 0;
        
        set<int> s;
        for(auto i:nums)
            s.insert(i);
        
        vector<int> res;
        for(auto i:s)
            res.push_back(i);
        
        int ans=1,temp=1;
        for(int i=1;i<res.size();i++)
        {
            if(res[i]==res[i-1]+1)
                temp++;
            
            else
            {
                ans=max(ans,temp);
                temp=1;
            }
        }
        
        ans=max(ans,temp);
        
        return ans;
        
    }
};