class TimeMap {
public:
        unordered_map <string , vector <int> > mp;
        unordered_map <int, string> timeVal;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(timestamp);
        timeVal[timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp[key].size() == 0)
            return "";
        auto it = lower_bound(mp[key].begin(), mp[key].end(),timestamp);
        if(it == mp[key].end())
        {
            it--;
        }
        if(it == mp[key].begin() && *it > timestamp)
        {
            return "";
        }
        if(*it > timestamp)
            it--;
        return timeVal[*it];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */