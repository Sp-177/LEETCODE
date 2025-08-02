class MedianFinder {
private:
    multiset<int> low, high;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            high.insert(num);
        }

        // Balance sizes
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            auto it = low.end();
            --it;
            low.erase(it);
        } else if (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    double findMedian() {
        if (low.size() == high.size()) {
            return (*low.rbegin() + *high.begin()) / 2.0;
        } else {
            return *low.rbegin();
        }
    }
};
