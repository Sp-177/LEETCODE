class Solution {
public:
    void func(vector<bool>&visit, vector<string>&ans,string output,int i,int n,int&k){
        if(i==n){ans.push_back(output);k--;return;}
        for(int j=1;j<=n;j++){
            if(!visit[j]){
                visit[j]=true;
                func(visit,ans,output+to_string(j),i+1,n,k);
                visit[j]=false;
            }
            if(k==0)return;
        }
    }
    string getPermutation(int n, int k) {
        vector<bool>visit(n+1);
        vector<string>ans;
        func(visit,ans,"",0,n,k);
        return ans[ans.size()-1];
    }
};