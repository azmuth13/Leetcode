class RandomizedSet {
public:
    
    unordered_map <int, int> mp,mp2;
    vector <int> v;
    int cnt;
    RandomizedSet() {
        cnt = 0;
    }
    
    bool insert(int val) {
        if(mp2.find(val) != mp2.end())
            return false;
        
        mp2[val] = cnt;
        mp[cnt] = val;
        v.push_back(cnt);
        cnt++;
        return true;
    }
    
    bool remove(int val) {
    
        if(mp2.find(val) == mp2.end())
            return false;
        
        int pos = mp2[val];
        mp.erase(pos);
        mp2.erase(val);
        auto it = lower_bound(v.begin(), v.end(), pos);
        v.erase(it);
        return true;
    }
    
    int getRandom() {
        int sz = v.size();
        int val = rand()%(sz);
        return mp[v[val]];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */