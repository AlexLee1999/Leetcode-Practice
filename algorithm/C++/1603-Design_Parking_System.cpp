class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        big_cap = big;
        medium_cap = medium;
        small_cap = small;
        big_num = 0;
        medium_num = 0;
        small_num = 0;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            return ++ big_num <= big_cap;
        } else if (carType == 2) {
            return ++ medium_num <= medium_cap;
        } else {
            return ++ small_num <= small_cap;
        }
        return true;
    }
private:
    int big_cap;
    int medium_cap;
    int small_cap;
    int big_num;
    int medium_num;
    int small_num;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */