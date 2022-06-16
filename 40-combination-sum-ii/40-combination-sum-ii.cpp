class Solution {
public:
    
    
    void findAllSubsets(int ind, int k, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds)
        {
            if(k<0)
                return;

            if(k==0)
            {
                res.push_back(ds);
                return;
            }

            for(int i=ind;i<arr.size();i++)
            {
                if(i>ind and arr[i]==arr[i-1])
                    continue;
                
                if(arr[i]<=k)
                {
                    ds.push_back(arr[i]);
                    findAllSubsets(i+1,k-arr[i],arr,res,ds);

                    ds.pop_back();
                }

            }
        }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        
         vector<vector<int>> res;
        vector<int> ds;
        
        sort(arr.begin(),arr.end());

        int ind=0;

        findAllSubsets(ind,k,arr,res,ds);

        return res;

        
    }
};