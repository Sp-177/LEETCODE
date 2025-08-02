class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i:nums)freq[i]++;
        vector<int>fq[100007];
        for(auto i:freq){
            fq[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(int i=1e5;i>=1;i--){
            
                while(fq[i].size()&&ans.size()<k){
                    ans.push_back(fq[i].back());
                    fq[i].pop_back();
                }
     
        }
        return ans;
    }
};