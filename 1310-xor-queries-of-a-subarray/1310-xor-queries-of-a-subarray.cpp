class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n=arr.size();
        
        vector<int> xorr(n);
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp^=arr[i];
            xorr[i]=temp;
        }
        
        vector<int> res;
        
        for(auto i:queries)
        {
            int left=i[0];
            int right=i[1];
            
            if(left==0)
                res.push_back(xorr[right]);
            
            else
            {
                int x=xorr[right]^xorr[left-1];
                res.push_back(x);
            }
            
        }
        
        return res;
        
    }
};