/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    

    TreeNode* solve(vector <int> &pre, vector <int> &ino, int i)
    {
        
        if(i == -1)
            return NULL;
        
        int ind = 0;
        for(int j = 0; j < ino.size(); j++)
        {
            if(ino[j]==pre[i])
            {
                ind = j;
                break;
            }
        }
            
        vector <int> left, right;
        
        for(int j = 0; j < ino.size(); j++)
        {
            if(j < ind)
            {
                left.push_back(ino[j]);
            }
            else if(j > ind)
            {
                right.push_back(ino[j]);
            }
        }
        
       
        unordered_map <int, int> f,g;
        for(auto x : right)
            f[x]++;
        
        for(auto x : left)
            g[x]++;
        
        int rightStart = -1;
        for(int k = 0; k < pre.size(); k++)
        {
            if(f.count(pre[k]))
            {
                rightStart = k;
                break;
            }
        }
        
        int leftStart = -1;
        for(int k = 0; k < pre.size(); k++)
        {
            if(g.count(pre[k]))
            {
                leftStart = k;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(pre[i]);
        
        root->left = solve(pre, left, leftStart);
        root->right = solve(pre, right, rightStart);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector <int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int n = preorder.size();
      
        TreeNode* ans = solve(preorder, inorder, 0);
        return ans;
       
    }
};