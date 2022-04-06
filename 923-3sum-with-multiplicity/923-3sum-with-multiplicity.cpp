class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n=arr.size();
        
        unordered_map<int,int> mp;
        
        int mod=1e9+7;
        
        int res=0;
        for(int i=0;i<n;i++)
        {
            int temp=mp[target-arr[i]];
            res=(res+(temp))%mod;
            
            for(int j=0;j<i;j++)
            {
                mp[arr[i]+arr[j]]++;
            }
        }
        
        return res;
        
        
//         int n = arr.size();
//         int mod = 1e9+7;
//         int ans = 0;
        
//         unordered_map<int, int> m;
        
//         for(int i=0; i<n; i++) 
//         {
//             ans = (ans + m[target - arr[i]]) % mod;
            
//             for(int j=0; j<i; j++)
//                 m[arr[i] + arr[j]]++;
//         }
        
//         return ans;
        
    }
};