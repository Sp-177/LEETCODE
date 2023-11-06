class SeatManager {
    private:
    priority_queue<int, vector<int>, greater<int>>seat;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            seat.push(i);
        }
    }
    
    int reserve() {
        int ans=seat.top();
        seat.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        seat.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */