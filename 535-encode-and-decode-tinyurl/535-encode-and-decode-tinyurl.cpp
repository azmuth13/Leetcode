class Solution {
public:

    // Encodes a URL to a shortened URL.
    
    string encode(string longUrl) {
        for(auto &x : longUrl)
            x -= 1;
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        for(auto &x : shortUrl)
            x += 1;
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));