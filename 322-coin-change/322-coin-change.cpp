class Solution {
public:
    
    int solve(int ind, int tar, vector<int> &coins,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(tar%coins[0]==0)
                return tar/coins[0];
            
            else
                return 1e9;
        }
        
        if(dp[ind][tar]!=-1)
            return dp[ind][tar];
        
        int notTake=solve(ind-1,tar,coins,dp);
        int take=1e9;
        
        if(coins[ind]<=tar)
            take=1+solve(ind,tar-coins[ind],coins,dp);
        
        return dp[ind][tar]=min(take,notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
            
            else
                dp[0][i]=1e9;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int notTake=dp[i-1][j];
                int take=1e9;
        
                if(coins[i]<=j)
                    take=1+dp[i][j-coins[i]];
        
                dp[i][j]=min(take,notTake);
            }
        }
        
        return ((dp[n-1][amount]==1e9) ? -1 : dp[n-1][amount]);
        
    }
};