class Twitter {
public:
    
    map <int, set <int> > mp;

    int count = 0;
    
    set < vector <int> , greater < vector <int> > > st;
    int p = 0;
        
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        
        st.insert({p, userId, tweetId});
        p++;
    }
    
    vector<int> getNewsFeed(int userId) {
        
        // userId's priority queue
        vector <int> ans;
        
        mp[userId].insert(userId);
        
        for(auto &x : st)
        {
            int poster = x[1];
            if(mp[userId].count(poster))
            {
                ans.push_back(x[2]);
            }
            
            if((int)ans.size() == 10)
                break;
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */