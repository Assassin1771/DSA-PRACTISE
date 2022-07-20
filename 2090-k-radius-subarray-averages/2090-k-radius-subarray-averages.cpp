class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            long long curr=nums[i];
            
            int prev_index=i-k, next_index=i+k;
            if(prev_index<0 or next_index>=n)
                res.push_back(-1);
            
            else
            {
                long long sum=0;
                
                long long left_sum=prefix[i];
                if(prev_index>0)
                    left_sum-=prefix[prev_index-1];
                
                long long right_sum=prefix[next_index]-prefix[i];
                
                sum+=left_sum+right_sum;
                
                res.push_back(sum/(2*k+1));
            }
        }
        
        return res;
    }
};