class Solution {
public:
    double myPow(double x, int n) {
   
        
//         0(N)
//         if(n==1)
//             return x;
        
//         if(n==0)
//             return (double)1;
        
//         double initial=x;
        
//         if(n<0)
//         {
//             n=abs(n);
//             int i=0;
//             for(i=0;i<=n;i++)
//             {
//                 x=x/initial;
                
//             }
            
//             cout<<i<<endl;
        
//             return x;
            
//         }
    
//         int i=0;
//         for(i=0;i<n-1;i++)
//         {
//             x=x*initial;
//         }
        
//         cout<<i<<endl;
        
//         return x;
        
        
        
        double res=1.0;
        
        long long nn=n;
        
        if(nn<0)
            nn=abs(nn);
        
        while(nn)
        {
            if(nn%2)
            {
                res=res*x;
                nn--;
            }
            
            else
            {
                x=x*x;
                nn=nn/2;
            }
        }
        
        if(n<0)
            return (double)1.0/(double)res;
        
        return res;
        
        
        
    }
};