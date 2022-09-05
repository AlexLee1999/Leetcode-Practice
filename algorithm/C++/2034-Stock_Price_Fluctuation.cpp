class StockPrice {
public:
    StockPrice() {
        cur_timestamp = 0;
        cur_price = 0;
    }
    
    void update(int timestamp, int price) {
        if (timestamp >= cur_timestamp) {
            cur_timestamp = timestamp;
            cur_price = price;
        }
        if (time_price.count(timestamp)) {
            prices[time_price[timestamp]] --;// handle multiple same price
            if (prices[time_price[timestamp]] == 0) {
                prices.erase(time_price[timestamp]);
            }
            prices[price] ++;
            time_price[timestamp] = price;
        } else {
            prices[price] ++;
            time_price[timestamp] = price;
        }
    }
    
    int current() {
        return cur_price;
    }
    
    int maximum() {
        int ans = prices.rbegin() -> first;
        return ans;
    }
    
    int minimum() {
        int ans = prices.begin() -> first;
        return ans;
    }
private:
    int cur_timestamp;
    int cur_price;
    unordered_map<int, int> time_price;
    map<int, int> prices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */