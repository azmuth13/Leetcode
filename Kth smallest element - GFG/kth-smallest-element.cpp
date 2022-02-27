// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    
    int partition(int arr[], int l, int r)
    {
        int i = l + 1;
        int piv = arr[l];
        
        for(int j = i; j <= r; j++)
        {
            if(arr[j] < piv)
            {
                swap(arr[j], arr[i]);
                i++;
            }
        }
        
        swap(arr[i-1], arr[l]);
        
        return i-1;
    }
    
    
    int quick_sort(int arr[], int l, int r, int k)
    {
        int pivot = partition(arr, l, r);
        
        int count = pivot+1;
        
        if(count == k)
        {
            return arr[pivot];
        }
        else if(count > k)
        {
            return quick_sort(arr, l, pivot - 1, k); 
        }
        else
        {
             return quick_sort(arr, pivot + 1, r, k);
        }
    }
    
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        // using quick select
            
        int i = l, j = r;
        
        // while(i < j)
        // {
        //     swap(arr[i], arr[j]);
        //     i++, j--;
        // }
        // i = l, j = r;
        
        while(i < j)
        {
            int ind = rand()%(j-i);
            swap(arr[i], arr[ind]);
            i++, j--;
        }
        
        return quick_sort(arr, l, r, k);
        
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends