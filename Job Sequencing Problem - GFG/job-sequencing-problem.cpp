// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static comp(Job j1, Job j2)
    {
        if(j1.profit>j2.profit)
        return true;
        
        if(j1.profit==j2.profit and j1.dead<j2.dead)
        return true;
        
        if(j1.profit==j2.profit and j1.dead==j2.dead and j1.id<j2.id)
        return true;
        
        return false;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr,arr+n,comp);
        
        int maxx=0;
        for(int i=0;i<n;i++)
        maxx=max(maxx,arr[i].dead);
        
        vector<int> temp(maxx+1,-1);
        
        int count=0,sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(temp[j]==-1)
                {
                    temp[j]=i;
                    count++;
                    sum+=arr[i].profit;
                    break;
                }
            }
        }
        
        
        vector<int> res;
        res.push_back(count);
        res.push_back(sum);
        
        return res;
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends