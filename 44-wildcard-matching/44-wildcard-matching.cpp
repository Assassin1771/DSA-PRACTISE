class Solution {
public:
    
    bool isAllStars(string & S1, int i)
    {
      for (int j = 1; j <= i; j++) 
      {
        if (S1[j - 1] != '*')
          return false;
      }
        
      return true;
    }
    
    bool wildcardMatchingUtil(string & S1, string & S2, int i, int j, vector < vector < int >> & dp) {
        
      if (i < 0 && j < 0)
        return true;
        
      if (i < 0 && j >= 0)
        return false;
        
      if (j < 0 && i >= 0)
        return isAllStars(S1, i);

      if (dp[i][j] != -1) return dp[i][j];

      if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);

      else {
        if (S1[i] == '*')
          return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else return false;
      }
    }
    
    bool isMatch(string s, string p) {
        
        string S1=p;
        string S2=s;
        
        int n=S1.length();
        int m=S2.length();
        
        vector < vector < int >> dp(n+1, vector < int > (m+1, -1));
        
        dp[0][0] = true;

      for (int j = 1; j <= m; j++) 
      {
        dp[0][j] = false;
      }
        
      for (int i = 1; i <= n; i++) 
      {
        dp[i][0] = isAllStars(S1, i);
      }

      for (int i = 1; i <= n; i++) 
      {
        for (int j = 1; j <= m; j++)
        {
          if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
            dp[i][j] = dp[i - 1][j - 1];

          else 
          {
            if (S1[i - 1] == '*')
              dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            else dp[i][j] = false;
          }
        }
      }

      return dp[n][m];
        
    }
};