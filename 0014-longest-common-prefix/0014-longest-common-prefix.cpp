class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0 || strs[0].size()==0){return "";}
        string ans="";
        bool flg=true;
        int index=0;
        while(flg){
            if(index>=strs[0].size()){break;}
            char c=strs[0][index];
            for(int i=0;i<strs.size();i++){
                if(index>=strs[i].size()||strs[i][index]!=c){
                    flg=false;
                    break;
                }
            }
            if(!flg){break;}
            ans+=c;
            index++;
        }
        return ans;
        
    }
};