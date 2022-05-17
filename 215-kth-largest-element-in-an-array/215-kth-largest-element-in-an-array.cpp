
class minheap{
    
    int a[100001];
    int n=0;
    public:
    
    minheap(){
        
    }
    
    void minHeapifyTOP(int a[], int n, int i)
    {
        // top -> to be used in pop
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
            
            minHeapifyTOP(a,n,lindex);
        }
    }
    
    void minHeapifyBOTTOM(int a[], int n, int i)
    {
       int parent = (i-1)/2;
        
        while(i != 0 && a[parent] > a[i])
        {
            swap(a[parent], a[i]);
            i = parent;
            parent = (i-1)/2;
        }
    }
    
    void buildHeap(int i)
    {
 
    }
    
    //---------------------//
    
    
    void push(int num)
    {   
        a[n] = num;
        int i = n;
        
        n++;

        minHeapifyBOTTOM(a, n, i);
    }
    
    int pop()
    {
        if(n == 0)
        {
            cout << "heap empty, returning -1";
            return -1;
        }
        
        int x = a[0];
        swap(a[0], a[n-1]);
        
        n-=1;
        
        minHeapifyTOP(a, n, 0);
        return x;
    }
    
    int top()
    {
        if(n == 0)
            return 1e9;
        
        return a[0];
    }
    
    int size()
    {
        if(n<=0)
            return 0;
        
        return n;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
//          min heap
        //priority_queue <int, vector <int> , greater <int> > pq;
        
         pair <minheap, minheap> pq;
        
        for(int i = 0; i < nums.size(); i++)
        {
            pq.first.push(nums[i]);
            
            if(pq.first.size() > k)
                pq.first.pop();
        }
        
        return pq.first.top();
        
    }
};