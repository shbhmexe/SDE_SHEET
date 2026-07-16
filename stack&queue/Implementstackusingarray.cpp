class myStack {
private:
    int* st;
    int top;
    int size;

public:
    myStack(int n) {
        size = n;
        st = new int[n];
        top = -1;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top >= size - 1) {
            return true;
        }
        return false;
    }

    void push(int x) {
        if (!isFull()) {
            top = top + 1;
            st[top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return st[top];
        }
        return -1;
    }
};