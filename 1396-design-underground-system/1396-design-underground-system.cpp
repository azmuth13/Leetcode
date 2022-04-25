class UndergroundSystem {
public:
    map <int, pair <string, int> > ugsLog;
    map <pair <string, string>, pair <int, int> > stLog;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ugsLog[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int t1 = ugsLog[id].second;
        string startStation = ugsLog[id].first;
        ugsLog.erase(ugsLog.find(id));
        
        int cnt = stLog[{startStation, stationName}].first;
        int sum = stLog[{startStation, stationName}].second;
        
        stLog[{startStation, stationName}] = {cnt + 1, sum + t - t1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        double cnt = stLog[{startStation, endStation}].first;
        double sum = stLog[{startStation, endStation}].second;
        
        return (double)sum/(double)cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */