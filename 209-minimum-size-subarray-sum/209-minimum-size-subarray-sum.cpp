class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        
        int i=0,j=-1;
        
        int res=1e9;
        while(i<n and j<n)
        {
            if(sum<target)
            {
                if(j+1>=n)
                    break;
                
                j++;
                sum+=nums[j];
            }
            
            else
            {
                res=min(res,j-i+1);
                sum-=nums[i];
                i++;
            }
            
            // cout<<i<<" "<<j<<" "<<sum<<endl;
        }
        
        if(res==1e9)
            return 0;
        
        return res;
        
    }
};

//SLIDING WINDOW VIA 2 POINTERS