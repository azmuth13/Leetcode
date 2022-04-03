
class Encrypter {
public:
    
   unordered_map<char, string>key;
    unordered_map<string, int>ct;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n = keys.size();
        for(int i=0;i<n;i++){
            key[keys[i]] = values[i];
        }
        for(auto& it:dictionary){
            ct[encrypt(it)]++;
        }
    }
    
    string encrypt(string word1) {
        int n = word1.size();
        string ret = "";
        for(int i=0;i<n;i++)ret+=key[word1[i]];
        return ret;
    }
    
    int decrypt(string word2) {
        if(ct.count(word2))return ct[word2];
        else return 0;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */