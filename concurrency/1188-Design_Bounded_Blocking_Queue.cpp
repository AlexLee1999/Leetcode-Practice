# include <semaphore.h>
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        sem_init(&s_enqueue, 0, capacity);
        sem_init(&s_dequeue, 0, 0);
    }
    
    void enqueue(int element) {
        sem_wait(&s_enqueue);
        m.lock();
        q.push(element);
        m.unlock();
        sem_post(&s_dequeue);
    }
    
    int dequeue() {
        sem_wait(&s_dequeue);
        m.lock();
        int res = q.front();
        q.pop();
        m.unlock();
        sem_post(&s_enqueue);
        return res;
    }
    
    int size() {
        return (int) q.size();
    }

private:
    sem_t s_enqueue;
    sem_t s_dequeue;
    mutex m;
    queue<int> q;
};