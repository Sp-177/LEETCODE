class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>S;
        int ans=0;
        for(auto i:s){
            if(S.find(i)!=S.end()){
                ans++;
                S.clear();
            }
            S.insert(i);
        }
        return ans+1;
    }
};