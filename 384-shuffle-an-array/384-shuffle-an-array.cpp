class Solution {
public:
    
    vector <int> init;
    vector <int> shuffled;
    
    Solution(vector<int>& nums) {
        
        init = nums;
    }
    
    vector<int> reset() {
        return init;
    }
    
    vector<int> shuffle() {

        vector <int> use = init;
        int i = 0;
        int n = use.size();
        
        int j = n-1;
        
        while(i < n)
        {
            int ind = rand()%(n-i);
            swap(use[i+ind], use[i]);
            i++;
        }
            
        return use;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */