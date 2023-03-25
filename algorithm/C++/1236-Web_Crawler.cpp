/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    bool isSameHost(const string& a, const string& b) {
        if (a.size() > b.size()) {
            return isSameHost(b, a);
        }
        for (int i=7; i<=a.size(); ++i) {
            if ((i == a.size() || a[i] == '/') && b[i] == '/') {
                return true;
            } else if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ans;
        ans.push_back(startUrl);
        queue<string> myQueue;
        myQueue.push(startUrl);
        unordered_set<string> visited;
        visited.insert(startUrl);
        while (!myQueue.empty()){
            string tmp = myQueue.front();
            myQueue.pop();
            vector<string> url = htmlParser.getUrls(tmp);
            for (int i=0; i<url.size(); ++i) {
                if (isSameHost(url[i], startUrl) && !visited.count(url[i])) {
                    myQueue.push(url[i]);
                    visited.insert(url[i]);
                    ans.push_back(url[i]);
                }
            }
        }
        return ans;
    }
};