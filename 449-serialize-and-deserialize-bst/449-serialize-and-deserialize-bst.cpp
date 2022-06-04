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

    // Encodes a tree to a single string.
    
    void helper(TreeNode* root, string &s)
    {
        if(!root)
        {
            s += "NULL,";
            return;
        }
        
        s += to_string(root->val) + ',';
        helper(root->left,s);
        helper(root->right,s);
    }
    
    string serialize(TreeNode* root) {
        
        string res = "";
        
        helper(root,res);
        
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
        idx = 0;
        int sz = data.size();
        
        int i = 0;
        while(i < sz)
        {
            string res = "";
            while(i < sz && data[i] != ',')
            {
                res += data[i];
                i++;
            }
            
            if(res == "NULL")
            {
                v.push_back(-1e9);
            }
            else
            {
                v.push_back(stoi(res));
            }
            i++;
        }
        
        return welper(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;