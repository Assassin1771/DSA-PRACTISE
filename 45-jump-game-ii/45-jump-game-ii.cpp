class Solution {
public:
    
    int minJumps(int ind, vector<int> &nums, vector<int> &dp)
    {
        int n=nums.size();
        if(ind>=n-1)
            return 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int minn=1e9;
        for(int i=1;i<=nums[ind];i++)
        {
            int temp=0;
            
            temp=1+minJumps(ind+i,nums,dp);
            
            minn=min(minn,temp);
        }
        
        return dp[ind]= minn;
    }
    
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1 or n==0)
            return 0;
        
        vector<int> dp(n+1,-1);
        
        return minJumps(0,nums,dp);
        
    }
};