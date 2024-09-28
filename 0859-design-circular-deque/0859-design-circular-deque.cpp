class MyCircularDeque {
public:
    int front, rear, n, size;
    vector<int> v;

    MyCircularDeque(int k) {
        n = k;
        v.resize(n);
        front = 0;
        rear = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + n) % n;
        v[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        v[rear] = value;
        rear = (rear + 1) % n;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % n;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + n) % n;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return v[(rear - 1 + n) % n];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == n;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */