class Solution {
public:
    
    void check(int x, int y, int l, vector<int> &nums, int target, vector<vector<int>> &res, set<pair<pair<int,int>,pair<int,int>>> &s)
    {
        
        int h=nums.size()-1;
        
        target-=(x+y);
        
        while(l<h)
        {
            long long temp=nums[l]+nums[h];
            
            if(temp==target)
            {
                s.insert({{x,y},{nums[l],nums[h]}});
                l++;
            }
            
            else if(temp<target)
                l++;
            
            else
                h--;
        }
    }
        
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        
        set<pair<pair<int,int>,pair<int,int>>> s;
        
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=nums[i];
                int y=nums[j];
                
                if(j<n-1)
                    check(x,y,j+1,nums,target,res,s);
            }
        }
        
        for(auto i:s)
        {
            int a=i.first.first;
            int b=i.first.second;
            
            int c=i.second.first;
            int d=i.second.second;
            
            vector<int> temp;
            
            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);
            temp.push_back(d);
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};