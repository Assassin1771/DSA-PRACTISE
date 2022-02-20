class Solution {
public:
    
//     bool check(int n)
//     {
//         for(int i=2;i<=sqrt(n);i++)
//         {
//             if(n%i==0)
//                 return false;
//         }
        
//         return true;
//     }
    
    int countPrimes(int n) {
        
//         int res=0;
//         for(int i=2;i<n;i++)
//         {
//             if(check(i))
//                 res++;
//         }
        
//         return res;
        
        int res=0;
        vector<bool> vis(n+1,0);
        
        for(int i=2;i<n;i++)
        {
            if(vis[i])
                continue;
            
            res++;
            
            for(long j=(long)i*i;j<n;j+=i)
                vis[j]=true;
        }
        
        return res;
        
    }
};