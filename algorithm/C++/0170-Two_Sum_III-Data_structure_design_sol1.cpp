class TwoSum {
public:
    TwoSum() {
        sorted = true;
    }
    
    void add(int number) {
        arr.push_back(number);
        sorted = false;
    }
    
    bool find(int value) {
        if (!sorted) {
            sort(arr.begin(), arr.end());
        }
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            if (arr[left] + arr[right] < value) {
                left ++;
            } else if (arr[left] + arr[right] > value) {
                right --;
            } else {
                return true;
            }
        }
        return false;
    }
private:
    bool sorted;
    vector<int> arr;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */