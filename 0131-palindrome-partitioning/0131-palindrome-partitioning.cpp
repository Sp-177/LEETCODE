class Solution {
public:
    vector<vector<string>>ans;
    bool check(string s,int i,int j){
        while(i<j){if(s[i]!=s[j])return false; i++;j--;}
        return true;
    }
    void func(string s,int index,vector<string>&out){
        if(index==s.size()){
            ans.push_back(out);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(check(s,index,i)){
                string temp=s.substr(index,i-index+1);
                out.push_back(temp);
                func(s,i+1,out);
                out.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>out;
        func(s,0,out);
        return ans;
    }
};