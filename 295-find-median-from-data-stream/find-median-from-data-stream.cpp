class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || maxHeap.top() > num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
        }
    }
    
    double findMedian() {
        int n = maxHeap.size();
        int m = minHeap.size();
        if(n > m){
            return maxHeap.top();
        }
        else if(m > n){
            return minHeap.top();
        }
        else{
            return ((double)maxHeap.top() + (double)minHeap.top())/2.0;
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */