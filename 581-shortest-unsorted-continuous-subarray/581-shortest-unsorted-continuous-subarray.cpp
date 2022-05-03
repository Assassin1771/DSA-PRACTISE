class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)
            return 0;
        
//         if(n==2)
//             return (nums[0]<=nums[1]?0:2);
        
//         int ind1=-1,ind2=-1;
//         int maxx=nums[0];
        
//         for(int i=1;i<n;i++)
//         {
//             if(nums[i]<nums[i-1] or nums[i]<maxx)
//             {
//                 if(ind1==-1)
//                 {
//                     ind1=i-1;
//                     ind2=i;
                    
//                     maxx=nums[i-1];
//                 }
                
//                 else
//                     ind2=i;
//             }
            
//             else
//                 maxx=nums[i];
//         }
        
//         if(ind1==-1 or ind2==-1)
//             return 0;
        
        int ind1=-1,ind2=-1;
        
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=temp[i])
            {
                if(ind1==-1)
                    ind1=i;
                
                else
                    ind2=i;
            }
        }
        
        if(ind1==-1 or ind2==-1)
            return 0;
        
        return abs(ind2-ind1+1);
        
    }
};