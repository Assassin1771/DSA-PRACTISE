class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> map;
        int sum=0;
        int res=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            
            if(sum==k)
                res++;
            
            if(map.find(sum-k)!=map.end())
                res+=map[sum-k];
            
            map[sum]++;
        }
        
        return res;
        
    }
};