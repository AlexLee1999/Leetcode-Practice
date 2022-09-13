class Node {
public:
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
private:
    int val;
    Node* next;
    friend class MyCircularQueue;
};

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        cap = k;
        head = new Node(0, nullptr);
        count = 0;
        ptr = head;
    }
    
    bool enQueue(int value) {
        if (count >= cap) {
            return false;
        }
        ptr->next = new Node(value, nullptr);
        ptr = ptr->next;
        count ++;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) {
            return false;
        }
        if (ptr == head->next) {
            ptr = head;
        }
        head->next = head->next->next;
        count --;
        return true;
    }
    
    int Front() {
        if (count == 0) {
            return -1;
        }
        return head->next->val;
    }
    
    int Rear() {
        if (count == 0) {
            return -1;
        }
        return ptr->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == cap;
    }
private:
    int cap;
    Node* ptr;
    Node* head;
    int count;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */