

class node{
public:
    char ch;
    node* child[26];
    bool isEnd;

    node(char c)
    {
        ch = c;
        isEnd = false;
        for(int i = 0; i < 26; i++) child[i] = NULL;
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    
    Trie() {
        root = new node('$');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* temp = root;

        for(char c : word)
        {
            if(temp->child[c-'a'] == NULL)
            {
                temp->child[c-'a'] = new node(c);
            }

            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* temp = root;

        for(auto c : word)
        {
            if(temp->child[c-'a'] == NULL)
                return false;

            temp = temp->child[c-'a'];
        }
        return temp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* temp = root;
        for(auto c : prefix)
        {
            if(temp->child[c-'a'] == NULL)
                return false;

            temp = temp->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */