// #define pair<pair<int,int>,int> datatype

class Solution {
public:
    
    void check(int x, vector<int> &nums, int l, set<pair<pair<int,int>,int>> &s)
    {
        int h=nums.size()-1;
        int start=l-1;
        
        while(l<h)
        {
            int y=nums[l]+nums[h]+x;
            
            if(y==0)
            {
                s.insert({{nums[start],nums[l]},nums[h]});
                l++;
            }
            
            else if(y>0)
                h--;
            
            else
                l++;
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        
        set<pair<pair<int,int>,int>> s;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            
            check(x,nums,i+1,s);
        }
        
        vector<vector<int>> res;
        
        for(auto i:s)
        {
            int a=i.first.first;
            int b=i.first.second;
            int c=i.second;
            
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);
            
            res.push_back(temp);
        }
        
        return res;
        
    }
};