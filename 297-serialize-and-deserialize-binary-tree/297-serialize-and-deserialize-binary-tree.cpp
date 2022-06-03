/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void helper(TreeNode* root, string &s)
    {
        if(!root)
        {
            s += "NULL,";
            return;
        }
        
        s += to_string(root->val) + ",";
        
        helper(root->left,s);
        helper(root->right,s);
    }
        
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res = "";
        
        helper(root, res);
        // cout << res << endl;
        return res;
    }
    
    int idx;
    TreeNode* welper(vector <int> &v)
    {
        if(idx >= v.size() || v[idx] == -1e9)
        {
            idx++;
            return NULL;
        }
     
        
        TreeNode* root = new TreeNode(v[idx++]);
        root->left = welper(v);
        root->right = welper(v);

        return root;
        
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector <int> v;
        // cout << data << endl;
        int sz = data.size();
        
        int i = 0;
        while(i < sz)
        {
            string val = "";
            while(i < sz && data[i] != ',')
            {
                val += data[i];
                i++;
            }
            if(val == "NULL")
            {
                v.push_back(-1e9);
            }
            else
            {
                int num = stoi(val);
                v.push_back(num);
            }
            i++;
        }
        idx = 0;
        return welper(v);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));