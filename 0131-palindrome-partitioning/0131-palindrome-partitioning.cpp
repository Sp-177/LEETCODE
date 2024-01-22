class Solution {
public:
    bool pal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;j--;
        }return true;
    }
    void func(string s,vector<vector<string>>&ans,vector<string>&output){
        if(s.size()==0){
            ans.push_back(output);
            return ;
        }
        for(int j=0;j<s.size();j++){
            if(pal(s.substr(0,j+1))){
                
                output.push_back(s.substr(0,j+1));
                func(s.substr(j+1,s.size()-1),ans,output);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>output;
        func(s,ans,output);
        return ans;
    }
};