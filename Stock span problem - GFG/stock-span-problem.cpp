// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
       // Your code here
       
       vector<int> ind(n,-1);
       stack<int> st;
       
       for(int i=n-1;i>=0;i--)
       {
           while(st.empty()==false and arr[i]>arr[st.top()])
           {
            //   cout<<st.top()<<" "<<i<<endl;
               ind[st.top()]=i;
               st.pop();
           }
           
           st.push(i);
       }
       
    //   for(auto i:ind)
    //   cout<<i<<" ";
       
       
      vector<int> res;
      for(int i=0;i<n;i++)
      {
          if(ind[i]==-1)
          res.push_back(i+1);
           
          else
          {
            int x=abs(ind[i]-i);   
            res.push_back(x);
          }
      }
      
      return res;
       
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends