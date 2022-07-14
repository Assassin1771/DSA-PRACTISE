class Solution {
public:
    
    void findPair(int i, int curr, vector<int> &nums,vector<vector<int>> &res)
    {
        int j=nums.size()-1;
       
        vector<int> temp(3,-1e9);
       
        while(i<j)
        {
            int sum=nums[i]+nums[j];
           
            if(sum+curr==0)
            {
                temp[0] = curr;
                temp[1]=nums[i];
                temp[2]=nums[j];
               
                while(i < nums.size() && nums[i] == temp[1]) i++;
                while(j >= 0 && nums[j] == temp[2]) j--;
               
                res.push_back(temp);
               
            }
           
            else if(sum+curr>0)
                j--;
           
            else
                i++;
        }
       
       
    }
   
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        int n=nums.size();
       
        vector<vector<int>> res;
       
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<n;i++)
        {
            int curr=nums[i];
           
            findPair(i+1,curr,nums,res);
                       
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
       
        return res;
       
    }

};