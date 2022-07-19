class SnapshotArray {
public:
    SnapshotArray(int length) {
        arr = vector<map<int, int>>(length, map<int, int>{{0, 0}});
        cur_stamp = 0;
    }
    
    void set(int index, int val) {
        arr[index][cur_stamp] = val;
    }
    
    int snap() {
        return cur_stamp++;
    }
    
    int get(int index, int snap_id) {
        auto it = arr[index].upper_bound(snap_id); // Find the index > snap_id, then minus one => snap_id <= time_stamp
        it --;
        return it->second;
    }
private:
    vector<map<int, int>> arr;
    int cur_stamp;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */