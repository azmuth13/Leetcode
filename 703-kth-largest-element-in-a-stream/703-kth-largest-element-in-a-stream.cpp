class KthLargest {
public:
    priority_queue <int, vector <int>, greater <int> > pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
         sort(nums.rbegin(), nums.rend());
        
        for(int i=0; i<min(k, (int)nums.size()); i++)
        {
            pq.push(nums[i]);
        }
    }
    
    int add(int val){

        pq.push(val);
        if(pq.size()  > kk)
        pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */