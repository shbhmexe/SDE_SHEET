class maxHeap {
private:
    int arr[100];
    int currSize = 0;

public:
    void push(int x) {
        currSize++;
        int idx = currSize;
        arr[idx] = x;
        
        while (idx > 1) {
            int parent = idx / 2;
            
            if (arr[parent] < arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else {
                return;
            }
        }
    }

    void pop() {
        if (currSize == 0) {
            return;
        }
        
        arr[1] = arr[currSize];
        currSize--;
        
        int i = 1;
        while (i <= currSize) {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            int largest = i;
            
            if (leftIdx <= currSize && arr[leftIdx] > arr[largest]) {
                largest = leftIdx;
            }
            
            if (rightIdx <= currSize && arr[rightIdx] > arr[largest]) {
                largest = rightIdx;
            }
            
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    int peek() {
        if (currSize == 0) {
            return -1;
        }
        return arr[1];
    }

    int size() {
        return currSize;
    }
};