// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
// class node{
// public:
//     char ch;
//     node* child[2];
//     bool isEnd;

//     node(char c)
//     {
//         ch = c;
//         isEnd = false;
//         for(int i = 0; i < 2; i++) child[i] = NULL;
//     }
// };

// class Trie {
// public:
//     /** Initialize your data structure here. */
//     node* root;
    
//     Trie() {
//         root = new node('$');
//     }
    
//     /** Inserts a word into the trie. */
//     void insert(string &word) {
//         node* temp = root;

//         for(char c : word)
//         {
//             if(temp->child[c-'0'] == NULL)
//             {
//                 temp->child[c-'0'] = new node(c);
//             }

//             temp = temp->child[c-'0'];
//         }
//         temp->isEnd = true;
//     }
    
//     /** Returns if the word is in the trie. */
//     bool search(string word) {
//         node* temp = root;

//         for(auto c : word)
//         {
//             if(temp->child[c-'0'] == NULL)
//                 return false;

//             temp = temp->child[c-'0'];
//         }
//         return temp->isEnd;
//     }
    
//     /** Returns if there is any word in the trie that starts with the given prefix. */
//     bool startsWith(string &prefix) {
//         node* temp = root;
//         for(auto c : prefix)
//         {
//             if(temp->child[c-'0'] == NULL)
//                 return false;

//             temp = temp->child[c-'0'];
//         }
//         return true;
//     }
    
//     void find(string &num, int &ans)
//     {
//         node* temp = root;
//         for(int i = 0; i < 32; i++)
//         {
//             char c = num[i];
            
//             if(c == '0')
//             {
//                 if(temp->child[1])
//                 {
//                     ans |= (1 << (31-i));
//                     temp = temp->child[1];
//                 }
//                 else
//                 {
//                     temp = temp->child[0];
//                 }
//             }
//             else
//             {
//                 if(temp->child[0])
//                 {
//                     ans |= (1 << (31-i));
//                     temp = temp->child[0];
//                 }
//                 else
//                 {
//                     temp = temp->child[1];
//                 }
//             }
//         }
//     }
    
// };


// class Solution{   
// public:
    
//     string getBin(int n)
//     {
//         string ans = "";
//         int i = 0;
//         while(n > 0)
//         {
//             int rem = n%2;
//             ans += '0' + rem;
//             n/=2;
//         }
//         while(ans.size() < 32)
//             ans += '0';
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }

//     int maxSubarrayXOR(int N, int nums[]){    
//         //code here
//         int n = N;
//         int ans = 0;
        
//         Trie trie;
//         int xor1 = 0;
//         string bin = getBin(xor1);
//         trie.insert(bin);
        
//         for(int i = 0; i < n; i++)
//         {
//             xor1 ^= nums[i];
//             string bin = getBin(xor1);
//             trie.insert(bin);
            
//             int res = 0;
            
//             trie.find(bin,res);
//             ans = max(ans, res);
//             //cout << xor1 << endl;
//         }
//         return ans;
//     }
// };

class Node
{
  public:
  Node *one,*zero;
  Node()
  {
      one=NULL;
      zero=NULL;
  }
};
class Trie
{
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *temp=root;
        for(int i=30;i>=0;i--)
        {
            if((1<<i)&num)
            {
                if(temp->one==NULL)
                {
                    temp->one=new Node();
                }
                temp=temp->one;
            }
            else
            {
                 if(temp->zero==NULL)
                {
                    temp->zero=new Node();
                }
                temp=temp->zero;
            }
        }
    }
    int find(int num)
    {
        int res=0;
        Node *temp=root;
        for(int i=30;i>=0;i--)
        {
            if((1<<i)&num)
            {
                if(temp->zero)
                {
                    res|=(1<<i);
                    temp=temp->zero;
                }
                else
                temp=temp->one;
            }
            else
            {
                if(temp->one)
                {
                    res|=(1<<i);
                    temp=temp->one;
                }
                else
                temp=temp->zero;
            }
        }
        return res;
    }
};
class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){ 
        Trie *root=new Trie();
        int x=0;
        if(N==1)
        return arr[0];
        root->insert(0);
       for(int i=0;i<N;i++)
       {
           x=x^arr[i];
           root->insert(x);
       }
       x=0;
       int maxi=0;
       for(int i=0;i<N;i++)
       {
           x^=arr[i];
           maxi=max(maxi,root->find(x));
       }
       return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends