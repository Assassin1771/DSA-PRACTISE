class Solution {
public:
    int maxArea(vector<int>& height) {
        
//         BRUTE O(N)
//         int n=height.size();
        
//         int res=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 int x=min(height[i],height[j]);
//                 x=x*(abs(j-i));
                
//                 res=max(res,x);
//             }
//         }
        
//         return res;
        
        int n=height.size();
        int i=0,j=n-1;
        
        int res=0;
        while(i<j)
        {
            int x=abs(j-i);
            x*=min(height[i],height[j]);
            
            res=max(res,x);
            
            if(height[i]>height[j])
                j--;
            
            else
                i++;
            
        }
        
        return res;
        
    }
};