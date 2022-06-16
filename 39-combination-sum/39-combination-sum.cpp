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
            if(arr[i]<=k)
            {
                ds.push_back(arr[i]);
                findAllSubsets(i,k-arr[i],arr,res,ds);
                
                ds.pop_back();
            }

        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        
        vector<vector<int>> res;
        vector<int> ds;

        int ind=0;

        findAllSubsets(ind,k,arr,res,ds);

        return res;
        
    }
};