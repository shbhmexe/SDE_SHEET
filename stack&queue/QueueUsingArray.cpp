class myQueue {
    int* q;
    int start, end;
    int size;
    int currSize;

public:
    myQueue(int n) {
        size = n;
        q = new int[n];
        start = end = -1;
        currSize = 0;
    }

    bool isEmpty() {
        if (currSize == 0) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (currSize == size) {
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        if (!isFull()) {
            if (currSize == 0) {
                start = end = 0;
            } else {
                end = (end + 1) % size;
            }
            q[end] = x;
            currSize++;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            if (currSize == 1) {
                start = end = -1;
            } else {
                start = (start + 1) % size;
            }
            currSize--;
        }
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return q[start];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return q[end];
    }
};