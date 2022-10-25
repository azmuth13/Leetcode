class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s = "", r = "";
        for(auto x : word1)
            s+=x;
        
        for(auto x : word2)
            r+=x;
        return s==r;
    }
};