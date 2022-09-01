class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty()|| maxheap.top()>num)
            maxheap.push(num);
        else
            minheap.push(num);
        
        if(maxheap.size() > minheap.size()+1)
        {
            int num = maxheap.top();
            maxheap.pop();
            minheap.push(num);
        }
        if(minheap.size() > maxheap.size()+1)
        {
            int num = minheap.top();
            minheap.pop();
            maxheap.push(num);
        }
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size())
            return maxheap.top();
        else if(maxheap.size() < minheap.size())
            return minheap.top();
        else 
            return double(maxheap.top()+minheap.top())/double(2.0) ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */