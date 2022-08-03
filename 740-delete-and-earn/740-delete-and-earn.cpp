class Solution {
public:
    
    int maxPoints(int ind, vector<int> &v, vector<int> &dp)
    {
        int n=v.size();
        
        if(ind>=n)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        return dp[ind]= max(v[ind]+maxPoints(ind+2,v,dp),maxPoints(ind+1,v,dp));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> v(1e4+10,0); //acts as house robber aray
        for(int i=0;i<n;i++)
            v[nums[i]]+=nums[i];
        
        vector<int> dp(1e4+10,-1);
        return maxPoints(0,v,dp);
        
    }
};