class FizzBuzz {
private:
    int n;
    mutex m1;
    mutex m2;
    mutex m3;
    mutex m4;
    

public:
    FizzBuzz(int n) {
        this->n = n;
        m2.lock();
        m3.lock();
        m4.lock();
        m1.unlock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i=1; i<=n; ++i) {
            m1.lock();
            if (i % 3 == 0 && i % 5 != 0) {
                printFizz();
            }
            m2.unlock();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i=1; i<=n; ++i) {
            m2.lock();
            if (i % 3 != 0 && i % 5 == 0) {
                printBuzz();
            }
            m3.unlock();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i=1; i<=n; ++i) {
            m3.lock();
            if (i % 3 == 0 && i % 5 == 0) {
                printFizzBuzz();
            }
            m4.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i=1; i<=n; ++i) {
            m4.lock();
            if (i % 3 != 0 && i % 5 != 0) {
                printNumber(i);
            }
            m1.unlock();
        }
    }
};