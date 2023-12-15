class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>m;
        for(int i=0;i<paths.size();i++){
            m[paths[i][0]]=paths[i][1];
            if(m.count(paths[i][1])==0){
            m[paths[i][1]]="_";}
        }
        string ans;
        for(auto i:m){
            if(i.second=="_"){ans=i.first; break;}
        }
        return ans;
    }
};