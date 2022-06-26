class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        int res=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                sum+=-1;
            
            else
                sum++;
            
            if(sum==0)
                res=i+1;
            
            else if(mp.find(sum)!=mp.end())
                res=max(res,i-mp[sum]);
            
            else
                mp[sum]=i;       
        }
        
        return res;
        
    }
};