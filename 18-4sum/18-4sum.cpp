class Solution {
public:
    
    void check(int x, int y, int l, vector<int> &nums, long long target1, vector<vector<int>> &res)
    {
        vector<int> temp1(4);
        
        int h=nums.size()-1;
        
        target1-=(x+y);
        while(l<h)
        {
            long long temp=nums[l]+nums[h];
            
            if(temp==target1)
            {
                temp1[0]=x;
                temp1[1]=y;
                temp1[2]=nums[l];
                temp1[3]=nums[h];
                
                while(l<nums.size() and nums[l]==temp1[2])
                    l++;
                
                while(h>=l and nums[h]==temp1[3])
                    h--;
                
                res.push_back(temp1);
            }
            
            else if(temp<target1)
                l++;
            
            else
                h--;
        }
    }
        
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        long long target1=target;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=nums[i];
                int y=nums[j];
                
                if(j<n-1)
                    check(x,y,j+1,nums,target1,res);
                
                while(j+1<n and nums[j]==nums[j+1])
                    j++;
            }
            
            while(i+1<n and nums[i]==nums[i+1])
                i++;
        }
        
        return res;
        
    }
};