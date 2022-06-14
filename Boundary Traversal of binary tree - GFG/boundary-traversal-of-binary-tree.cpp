// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:


    void getLeftB(Node *root, vector <int> &v)
    {
        if(!root)
        return;
        
        
        if(root->left)
        {
            v.push_back(root->data);
            getLeftB(root->left, v);
        }
        else if(root->right)
        {
            v.push_back(root->data);
            getLeftB(root->right, v);
        }
        
    }
    
    void getRightB(Node *root, vector <int> &v)
    {
        if(!root)
        return;
        
        if(root->right)
        {
            getRightB(root->right, v);
            v.push_back(root->data);
            
        }
        else if(root->left)
        {
            getRightB(root->left, v);
            v.push_back(root->data);
            
        }
        
    }
    
    void getLeaf(Node *root, vector<int> &v)
    {
        if(!root)
        return;
        
    
            getLeaf(root->left, v);
            
        if(!root->left && !root->right)    
        v.push_back(root->data);
        

            getLeaf(root->right, v);
        
        
        
    }


    vector <int> boundary(Node *root)
    {
        //Your code here
        
        
        vector <int> leftB;
        
        getLeftB(root->left, leftB);
        
        vector <int> rightB;
        
        getRightB(root->right, rightB);
        
        vector <int> leaf1, leaf2;
        
        getLeaf(root->left, leaf1);
        getLeaf(root->right, leaf2);
        
        vector <int> ans;
        ans.push_back(root->data);
        
        ans.insert(ans.end(), leftB.begin(), leftB.end());
        
        ans.insert(ans.end(), leaf1.begin(), leaf1.end());
        ans.insert(ans.end(), leaf2.begin(), leaf2.end());
        //reverse(rightB.begin(), rightB.end());
        
        //rightB.pop_back();
        
        ans.insert(ans.end(), rightB.begin(), rightB.end());
        
        // for(int i = 0; i < leftB.size(); i++)
        // cout<<leftB[i]<<" ";
        // cout<<endl;
        
        //  for(int i = 0; i < leaf.size(); i++)
        // cout<<leaf[i]<<" ";
        // cout<<endl;
        
        //  for(int i = 0; i < rightB.size(); i++)
        // cout<<rightB[i]<<" ";
        // cout<<endl;
        
        
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends