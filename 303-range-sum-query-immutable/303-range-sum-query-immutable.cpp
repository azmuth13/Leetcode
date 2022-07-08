class NumArray {
    vector <int> pref;
public:
    
    NumArray(vector<int>& nums) {
        int sz = nums.size();
        pref.resize(sz,0);
        for(int i = 0; i < sz; i++)
        {
            pref[i] += ((i>0)?pref[i-1]:0) + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right]-((left>0)?pref[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */