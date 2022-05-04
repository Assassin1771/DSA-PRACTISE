class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(n==1)
            return 0;
        
        int res=0;
        
        sort(nums.begin(),nums.end());
        
        int i=0,j=n-1;
        while(i<j)
        {
            int val=nums[i]+nums[j];
            
            if(val==k)
            {
                res++;
                i++;
                j--;
            }
            
            else if(val<k)
            {
                i++;
            }
            
            else
                j--;
        }
        
        return res;
        
    }
};