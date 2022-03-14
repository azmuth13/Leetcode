int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class MovieRentingSystem {
public:
    
    #define pppi pair<int, pair <int, int>> 
    
    set < pppi > unrented,rented;
    
    map < pair <int, int>, int > mp;
    //unordered_map < int, unordered_map <int,int>  > mp;
    
    unordered_map <int, set < pair <int, int> > > movies;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
        
        for(int i = 0; i < entries.size(); i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            
            //unrented.insert({price, shop, movie});
            
            unrented.insert({price, {shop, movie}});
            mp[{shop,movie}] = price;
            
           // mp[shop][movie] = price;
            
            movies[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        
        // return a list of 5 cheapest shops that have the given movie
        
        vector <int> ans;
        
        for(auto x : movies[movie])
        {
            if((int)ans.size()==5)
                break;
            
            ans.push_back(x.second);
        }
        
        return ans;
    }
    
    void rent(int shop, int movie) {
        // remove the movie from the given shop
        
        int price = mp[{shop,movie}];
       // rented.insert({price, shop, movie});
        
        rented.insert({price, {shop, movie}});

       // unrented.erase({price, shop, movie}); 
        
        unrented.erase({price, {shop, movie}}); 

        movies[movie].erase(movies[movie].find({price,shop}));
    }
    
    void drop(int shop, int movie) {
        // return or add
        
        int price = mp[{shop,movie}];
        //unrented.insert({price, shop, movie});
        
        unrented.insert({price, {shop, movie}});

        movies[movie].insert({price,shop});
        //rented.erase({price, shop, movie}); 
        
        rented.erase({price, {shop, movie}}); 
    }
    
    vector<vector<int>> report() {
        // return the 5 cheapest rented movies as {shop, movie}
        
        vector<vector<int>> ans;
        
        for(auto x : rented)
        {
            if(ans.size() == 5)
                break;
            
            int shop =  x.second.first;
            int movie = x.second.second;
            
            ans.push_back({shop,movie});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */