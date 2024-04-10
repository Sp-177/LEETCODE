class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>arr(deck.size());
        sort(deck.begin(),deck.end());
        int index=deck.size()-1;
        deque<int>d;
        d.push_back(deck[index--]);
        while(index>=0){
            int b=d.back();
            d.pop_back();
            d.push_front(b);
            d.push_front(deck[index]);
            index--;
        }
        vector<int>ans;
        for(int i:d){
            ans.push_back(d.front());
            d.pop_front();
        }
        return ans;
    }
};