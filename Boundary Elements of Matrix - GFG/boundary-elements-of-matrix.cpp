// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    vector<int> BoundaryElements(vector<vector<int>>&matrix){
        // Code here
        
        int n=matrix.size();
        
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or i==n-1)
                res.push_back(matrix[i][j]);
                
                else
                {
                    res.push_back(matrix[i][0]);
                    res.push_back(matrix[i][n-1]);
                    
                    break;
                }
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution obj;
		vector<int>ans = obj.BoundaryElements(matrix);
		for(auto i: ans)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends