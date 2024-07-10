class MedianFinder {
public:
    priority_queue<double>mini;
    priority_queue<double,vector<double>,greater<double>>maxi;
    double mid=INT_MIN;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int leftsize=mini.size();
        int rightsize=maxi.size();
        if(mid==INT_MIN){mid=num;}
        else{
            if(num>mid){
                maxi.push(num);
            }
            else{
                mini.push(num);
            }
            
                if(mini.size()>maxi.size() &&(mini.size()-maxi.size()>1)){
                    maxi.push(mid);
                    mid=mini.top();
                    mini.pop();
                }
                else if(maxi.size()>mini.size() &&(maxi.size()-mini.size()>1)){
                    mini.push(mid);
                    mid=maxi.top();
                    maxi.pop();
                }
            
        }
        // cout<<mini.size()<<' '<<maxi.size();

    }
    
    double findMedian() {
        int leftsize=mini.size();
        int rightsize=maxi.size();
        int len=leftsize+rightsize+1;
        // cout<<len<<endl;
        if(len&1){
            return mid;
        }
        return (mid+(leftsize>rightsize?mini.top():maxi.top()))/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */