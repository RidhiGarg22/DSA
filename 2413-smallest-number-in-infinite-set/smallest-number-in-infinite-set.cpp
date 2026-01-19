class SmallestInfiniteSet {
private:
    int nextNum;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> inHeap;

public:
    SmallestInfiniteSet() {
        nextNum = 1;
    }

    int popSmallest() {
        int result;
        if (!minHeap.empty()) {
            result = minHeap.top();
            minHeap.pop();
            inHeap.erase(result);
        } else {
            result = nextNum;
            nextNum++;
        }
        return result;
    }

    void addBack(int num) {
        if (num < nextNum && inHeap.find(num) == inHeap.end()) {
            minHeap.push(num);
            inHeap.insert(num);
        }
    }
};
