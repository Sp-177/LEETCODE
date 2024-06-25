class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<string>strs=s;
        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }
        vector<bool>visit(strs.size(),false);
         vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            vector<string>out;
            if(visit[i]==false){
            for(int j=i;j<strs.size();j++){
                if(strs[i]==strs[j]){
                    out.push_back(s[j]);
                    visit[j]=true;
                }
            }
            ans.push_back(out);
            }
        }
        return ans;
    }
};