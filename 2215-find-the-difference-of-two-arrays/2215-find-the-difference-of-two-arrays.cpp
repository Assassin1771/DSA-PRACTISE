class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> res;
        vector<int> temp;
        
        int m=nums1.size();
        int n=nums2.size();
        
        map<int,int> mp1,mp2;
        
        set<int> s1,s2;
        for(int i=0;i<m;i++)
            s1.insert(nums1[i]);
        
        for(int i=0;i<n;i++)
            s2.insert(nums2[i]);
        
        for(auto i:s1)
        {
            mp1[i]++;
            mp2[i]--;
        }
        
        for(auto i:s2)
        {
            mp1[i]--;
            mp2[i]++;
        }
        
//         for(auto i:s1)
//             cout<<i<<" ";
        
//         cout<<endl;
        
//         for(auto i:s2)
//             cout<<i<<" ";
        
        
        
        for(auto [x,y]:mp1)
        {
            // cout<<x<<" "<<y<<endl;
            if(y==1)
                temp.push_back(x);
        }
        
        cout<<endl;
        
        res.push_back(temp);
        
        temp.clear();
        
        for(auto [x,y]:mp2)
        {
            // cout<<x<<" "<<y<<endl;
            if(y==1)
                temp.push_back(x);
        }
        
        res.push_back(temp);
        
        return res;
        
        
    }
};