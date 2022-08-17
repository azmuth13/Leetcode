class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> res = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set <string> st;
        
        for(auto x : words)
        {
            string curr = "";
            for(int i = 0; i < x.size(); i++)
            {
                curr += res[x[i]-'a'];
            }
            st.insert(curr);
        }
        
        return st.size();
    }
};