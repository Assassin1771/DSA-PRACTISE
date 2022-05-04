class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        unordered_map<int,int> mp;
        
        int res=0;
        for(auto i:nums)
        {
            if(mp[k-i]>0)
            {
                res++;
                mp[k-i]--;
            }
            
            else
                mp[i]++;
        }
        
        return res;
        
    }
};