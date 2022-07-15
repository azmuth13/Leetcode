class LRUCache {
public:
    unordered_map <int, int> mp, cnt;
    int cap;
    queue <int> q;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cnt.find(key) == cnt.end())
            return -1;
        
        cnt[key]++;
        q.push(key);
        return mp[key];
    }
    
    void put(int key, int value) {
        mp[key] = value;
        cnt[key]++;
        q.push(key);
        
        while(cnt.size() > cap)
        {
            int fkey = q.front();
            q.pop();
            cnt[fkey]--;
            if(cnt[fkey]==0)
            {
                cnt.erase(fkey);
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */