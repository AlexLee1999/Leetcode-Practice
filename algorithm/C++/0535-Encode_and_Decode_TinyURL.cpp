class Solution {
public:
    Solution () {
        count = 0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = to_string(count);
        myMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return myMap[shortUrl];
    }
private:
    int count;
    unordered_map<string, string> myMap;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));