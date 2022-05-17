class Solution {
public:
    
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
    
    int rand_partition(int arr[], int start, int end)
    {
        int randomPivot = start + rand()%(end-start+1);
    
        swap(arr[start], arr[randomPivot]);
    
        return partition(arr, start, end);
    }
    
    
    int quick_sort(int arr[], int l, int r, int k)
    {
        int pivot = partition(arr, l, r);
        
        int count = r-pivot+1;
        
        if(count == k)
        {
            return arr[pivot];
        }
        else if(count > k)
        {
            return quick_sort(arr, pivot + 1, r, k); 
        }
        else
        {
             return quick_sort(arr, l, pivot - 1, k);
        }
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue <int, vector <int> , greater <int> > pq;
            
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
        
//         int arr[nums.size()];
        
//         for(int i = 0; i < nums.size(); i++)
//             arr[i] = nums[i];
        
        
        
//         return quick_sort(arr, 0, nums.size()-1, k);
        
    }
};