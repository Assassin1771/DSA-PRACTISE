class Solution {
public:
    
    int check(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind==nums.size())
            return 0;
        
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1];
        
        int len=0;
        len=check(ind+1,prev,nums,dp);
        
        if(prev==-1 or nums[ind]>nums[prev])
            len=max(len, 1+check(ind+1,ind,nums,dp));
        
        return dp[ind][prev+1]=len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        
        int ind=0,prev=-1;
        
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        
        return check(ind, prev, nums,dp);
        
    }
};