class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int res=0;
        
        int i=n-1;
        while(i>=0)
        {
            // cout<<i<<endl;
            
            int key=nums[i];
            i--;
            
            while(i>=0)
            {
                if(abs(key-nums[i])<=k)
                    i--;
                
                else
                    break;
            }
            
            res++;
        }
        
        return res;
        
    }
};