class Solution {
public:
    
    long long merge(vector<int> &nums, int l, int m, int h)
    {
        int n1=m-l+1;
        int n2=h-m;
        
        int left[n1], right[n2];
        
        for(int i=0;i<n1;i++)
            left[i]=nums[l+i];
        
        for(int i=0;i<n2;i++)
            right[i]=nums[m+1+i];
        
        int i=0,j=0,k=l;
        long long res=0;
        while(i<n1 and j<n2)
        {
            if(left[i]<=right[j])
            {
                nums[k]=left[i];
                k++;
                i++;
            }
            
            else
            {
                nums[k]=right[j];
                k++;
                j++;
                
                res+=(n1-i);
            }
        }
        
        while(i<n1)
        {
            nums[k]=left[i];
            k++;
            i++;
        }
        
        while(j<n2)
        {
            nums[k]=right[j];
            k++;
            j++;
        }
        
        return res;
    }
    
    long long mergeSort(vector<int> &nums, int l, int h)
    {
        long long res=0;
        if(h>l)
        {
            int m=l+(h-l)/2;
            
            res+=mergeSort(nums,l,m);
            res+=mergeSort(nums,m+1,h);
            
            res+=merge(nums,l,m,h);
        }
        
        return res;
    }
    
    bool isIdealPermutation(vector<int>& nums) {
        
        int n=nums.size();
        
        long long local_inversions=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
                local_inversions++;
        }
        
        long long global_inversions=0;
        
        int low=0, high=n-1;
        global_inversions=mergeSort(nums, low, high);
        
        return (local_inversions==global_inversions);
        
    }
};