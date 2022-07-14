class Node {
public:
    Node() {
        val = 0;
        next = nullptr;
    }
private:
    int val;
    Node* next;
    friend class MyLinkedList;
};
class MyLinkedList {
public:
    MyLinkedList() {
        dummy = new Node();
        dummy->val = 0;
        size = 0;
    }
    
    int get(int index) {
        Node* ptr = dummy->next;
        if (index >= size) {
            return -1;
        }
        for (int i=0; i<index; ++i) {
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node();
        node->val = val;
        node->next = dummy->next;
        dummy->next = node;
        size ++;
    }
    
    void addAtTail(int val) {
        Node* ptr = dummy;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        Node* node = new Node();
        node->val = val;
        ptr->next = node;
        size ++;
    }
    
    void addAtIndex(int index, int val) {
        Node* ptr = dummy;
        if (index > size) {
            return;
        }
        for (int i=0; i<index; ++i) {
            ptr = ptr->next;
        }
        Node* node = new Node();
        node->val = val;
        node->next = ptr->next;
        ptr->next = node;
        size ++;
    }
    
    void deleteAtIndex(int index) {
        Node* ptr = dummy;
        if (index >= size) {
            return;
        }
        for (int i=0; i<index; ++i) {
            ptr = ptr->next;
        }
        if (ptr->next != nullptr) {
            ptr->next = ptr->next->next;
        }
        size --;
        return;
    }
private:
    Node* dummy;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */