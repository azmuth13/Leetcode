// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class minheap{
    public:
    int a[100005];
    
    int n = 0;
    
    minheap()
    {
        // for(int i = 0; i < sz; i++)
        // {
           
        //     a[i] = arr[i];
        //     n++;
        // }
        
        // BuildHeap(a,n);
    }
    
    
    void minHeapyfy(int a[], int n, int i)
    {
        int lindex = i;
        int left = 2*i+1;
        int right = 2*i + 2;
        
        if(left < n && a[left] < a[lindex])
        lindex = left;
        
        if(right < n && a[right] < a[lindex])
        lindex = right;
        
        if(lindex!=i)
        {
            // swapping
            int temp = a[i];
            a[i] = a[lindex];
            a[lindex] = temp; 
            
            minHeapyfy(a,n,lindex);
        }
    }
    
    void BuildHeap(int a[], int n)
    {
        for(int i=n/2; i>=0; i--)
        minHeapyfy(a,n,i);
    }
    
    /* --------------------------------- */
    

    
    void push(int x)
    {
        a[n] = x;
        
        int i = n;
        n+=1;
        
        int parent = (i-1)/2;
        
        while(i!=0  && a[parent] > a[i])
        {
            swap(a[parent], a[i]);
            i = parent;
            parent = (i-1)/2;
        }
      
        //BuildHeap( a,  n);
    }
    
    int pop()
    {
        if(n==0)
        {
            cout << "pq empty\n";
            return -1;
        }

        int x = a[0]; // to be deleted
        
        swap(a[0], a[n-1]);
        n-=1;
        
        minHeapyfy(a,n,0);
        
        return x;
    }
    
    int top()
    {
        if(n==0)
        {
            cout << "pq empty\n";
            return -1;
        }
        return a[0];
    }
    
    int size()
    {
        if(n <=0)
            return 0;

        return n;
    }
    
};
  
 class Solution{
  public:
        
    
    vector<int> kthLargest(int k, int a[], int n) {
        // code here
        
        minheap pq;
        vector <int> ans;
        
        //priority_queue <int, vector <int> , greater <int> > pq;
        
        for(int i = 0; i < n; i++)
        {
            
            if(i < k-1)
            {
                ans.push_back(-1);
                pq.push(a[i]);
            }
            else
            {
                if(i==k-1)
                pq.push(a[i]);
                else
                {
                    if(pq.top() < a[i])
                    {
                        pq.pop();
                        pq.push(a[i]);
                    }
                }
                
                ans.push_back(pq.top());
            }
        }
        return ans;
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends