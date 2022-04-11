class Solution {
public:
    
    int check(int ind, int buy, int cap, vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(ind==prices.size())
            return 0;
        
        if(cap==0)
            return 0;
        
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];
        
        int profit=0;
        if(buy)
        {
            profit=max(-prices[ind]+check(ind+1,0,cap,prices,dp),check(ind+1,1,cap,prices,dp));
        }
        
        else
        {
            profit=max(prices[ind]+check(ind+1,1,cap-1,prices,dp),check(ind+1,0,cap,prices,dp));
        }
        
        return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        // int buy=1;
        // int cap=2;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
        
        // return check(0,buy,cap,prices,dp);
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit=max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    }

                    else
                    {
                        profit=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }

                    dp[ind][buy][cap]=profit;
                }
            }
        }
        
        return dp[0][1][2];
        
        
        
    }
};