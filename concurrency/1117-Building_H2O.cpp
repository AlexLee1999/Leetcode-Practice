# include <semaphore.h>
class H2O {
public:
    H2O() {
        sem_init(&sem_h, 0, 1);
        sem_init(&sem_o, 0, 0);
        h = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&sem_h);
        m.lock();
        h ++;
        m.unlock();
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        if (h % 2 == 0) {
            sem_post(&sem_o);
        } else {
            sem_post(&sem_h);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&sem_o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&sem_h);
    }
private:
    sem_t sem_h;
    sem_t sem_o;
    mutex m;
    int h;
};