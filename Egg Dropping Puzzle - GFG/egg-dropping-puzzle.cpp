// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int fun(int e, int f, vector<vector<int>> &dp)
    {
        if(e==1)
        return f;
        
        if(f==1 or f==0)
        return f;
        
        if(dp[e][f]!=-1)
        return dp[e][f];
        
        int minn=1e9;
        for(int k=1;k<=f;k++)
        {
            int temp=1+max(fun(e-1,k-1,dp),fun(e,f-k,dp));
            minn=min(minn,temp);
        }
        
        return dp[e][f]= minn;
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        return fun(n,k,dp);
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends