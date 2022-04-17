// int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

// class MovieRentingSystem {
// public:
    
//     #define pppi pair<int, pair <int, int>> 
    
//     set < pppi > unrented,rented;
    
//     map < pair <int, int>, int > mp;
    
//     // facilitates search by storing the prices and shops a particular movie is associated with
//     unordered_map <int, set < pair <int, int> > > movies;
    
//     MovieRentingSystem(int n, vector<vector<int>>& entries) {
        
//         for(int i = 0; i < entries.size(); i++)
//         {
//             int shop = entries[i][0];
//             int movie = entries[i][1];
//             int price = entries[i][2];
            
//             // initially all movies are unrented
//             unrented.insert({price, {shop, movie}});
            
//             // store the price for each pair of {shop,movie}. remember this pair is unique as given in the problem statement
//             mp[{shop,movie}] = price;
            
//             // store all the movies with their price and shop
//             movies[movie].insert({price,shop});
//         }
//     }
    
//     vector<int> search(int movie) {
        
//         // return a list of 5 cheapest shops that have the given movie
        
//         vector <int> ans;
        
//         for(auto x : movies[movie])
//         {
//             if((int)ans.size()==5)
//                 break;
            
//             ans.push_back(x.second);
//         }
        
//         return ans;
//     }
    
//     void rent(int shop, int movie) {
//         // remove the movie from the given shop
        
//         int price = mp[{shop,movie}];
    
//         // add this movie in rented
//         rented.insert({price, {shop, movie}});
        
//         // remove this movie from unrented
//        // unrented.erase({price, {shop, movie}}); 
        
//         // also, erase this shop from the movies, since this movie will be no longer present in the given shop
//         movies[movie].erase(movies[movie].find({price,shop}));
//     }
    
//     void drop(int shop, int movie) {
//         // return or add
        
//         int price = mp[{shop,movie}];

//         // add in unrented as movie is back in the shop
//         //unrented.insert({price, {shop, movie}});
        
//         movies[movie].insert({price,shop});
        
//         // remove from rented
//         rented.erase({price, {shop, movie}}); 
//     }
    
//     vector<vector<int>> report() {
//         // return the 5 cheapest rented movies as {shop, movie}
        
//         // here comes the use of rented data structure, since we can quickly select 5 cheapest movies that are rented 
//         vector<vector<int>> ans;
        
//         for(auto x : rented)
//         {
//             if(ans.size() == 5)
//                 break;
            
//             int shop =  x.second.first;
//             int movie = x.second.second;
            
//             ans.push_back({shop,movie});
//         }
//         return ans;
//     }
// };

// /**
//  * Your MovieRentingSystem object will be instantiated and called as such:
//  * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
//  * vector<int> param_1 = obj->search(movie);
//  * obj->rent(shop,movie);
//  * obj->drop(shop,movie);
//  * vector<vector<int>> param_4 = obj->report();
//  */

class MovieRentingSystem {
public:
    map<pair<int, int>, int> priceMap;          // [shop, movie] -> price
    map<int, set<pair<int, int>>> movieSets;    // movie -> set of [price, shop]
    set<tuple<int, int, int>> rentedSet;        // [price, shop, movie]

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto v : entries) {
            int shop = v[0], movie = v[1], price = v[2];
            priceMap[{shop, movie}] = price;
            movieSets[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ret;
        set<pair<int, int>> st = movieSets[movie];
        auto it = st.begin();
        while ((int)ret.size() < 5 && it != st.end()) {
            ret.push_back(it->second);
            it++;
        }
        return ret;
    }

    void rent(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        // Remove from movie set
        //set<pair<int, int>> st = movieSets[movie];
        //st.erase({price, shop});
        movieSets[movie].erase({price, shop});
        // Add into rented set
        rentedSet.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[{shop, movie}];
        // Add to movie set
        //set<pair<int, int>> st = movieSets[movie];
        //st.insert({price, shop});
        movieSets[movie].insert({price, shop});
        // Remove from rented set
        rentedSet.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ret;
        auto it = rentedSet.begin();
        while ((int)ret.size() < 5 && it != rentedSet.end()) {
            ret.push_back({get<1>(*it), get<2>(*it)});
            it++;
        }
        return ret;
    }
};