class Solution {
private:
    void func(string digits,vector<string>&ans,vector<string>&map,string output){
        if(digits.size()==0){
            if(output.size()!=0){
            ans.push_back(output);}
            return;
        }
        int x=digits[0]-'0';
        for(int i=0;i<map[x].size();i++){
            func(digits.substr(1),ans,map, output+map[x][i]);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>map={"00","00","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        func(digits,ans,map,"");
        return ans;
    }
};