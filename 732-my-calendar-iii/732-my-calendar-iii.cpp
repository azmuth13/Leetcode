class MyCalendarThree {
public:
    map <int,int>mp;
    MyCalendarThree() {
        mp.clear();
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        map <int, int> mp2 = mp;
        for(auto x : mp2)
        {
            sum += x.second;
            mp2[x.first] = sum;
        }
        
        int maxi = 0;
        for(auto x : mp2)
        {
            //cout << x.first << ' ' << x.second<<endl;
            maxi = max(maxi, x.second);
        }
        //cout << endl;
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */