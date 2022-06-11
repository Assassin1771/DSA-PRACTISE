class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& mat) {
        
        int n=nums.size();
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<mat.size();i++)
        {
            int ind=mp[mat[i][0]];
            
            nums[ind]=mat[i][1];
            
            mp[mat[i][1]]=mp[mat[i][0]];
        }
        
        return nums;
        
    }
};