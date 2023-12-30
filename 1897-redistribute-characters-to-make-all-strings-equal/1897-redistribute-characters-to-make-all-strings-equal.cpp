class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>map;
        for(auto i:words){
            for(auto j : i){
                map[j]++;
            }
        }
        for(auto i:map){
            if(i.second%words.size()!=0)return false;
        }
        return true;
    }
};