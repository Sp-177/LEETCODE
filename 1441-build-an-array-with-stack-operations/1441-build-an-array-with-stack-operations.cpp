class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int x=1;
        int y=target[target.size()-1];
        int i=0;
        while(y>=x &&x<=n){
            ans.push_back("Push");
            if(target[i]!=x){ans.push_back("Pop");}
            else{i++;}
            x++;
        }
        return ans;
    }
};