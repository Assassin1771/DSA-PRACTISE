class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n= nums.size();
        int sum=0, count=0;
        
        map<int, int>s;
        
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
         
            if(sum==k)
            {
                // cout<<"a"<<endl;
                count++;
            }
                
            
            if(s.find(sum-k)!=s.end())
            {
                // cout<<"b"<<' '<<sum<<endl;
                count+=s[sum-k];
            }
            
            s[sum]++;
        } 
        
        // for(auto [x,y]:s)
        //     cout<<x<<" "<<y<<endl;
        
        return count;

        
    }
};