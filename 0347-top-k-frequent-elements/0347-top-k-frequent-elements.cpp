class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i:nums)freq[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        for(auto i:freq){
            int f=i.second;
            int num=i.first;
            if(min_heap.size()==k){
                if(f>min_heap.top().first){
                    min_heap.pop();
                }
                else continue;
            }
            min_heap.push({f,num});
            
        }
        vector<int>ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};