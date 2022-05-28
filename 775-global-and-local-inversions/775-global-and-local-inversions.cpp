class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int mx = 0;
        for(int i=0;i<(int)nums.size()-2;i++) {
            mx = max(mx, nums[i]);
            if(mx > nums[i + 2]) return false;
        }
        return true;
    }
};